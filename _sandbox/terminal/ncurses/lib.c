#define _XOPEN_SOURCE_EXTENDED
#include <locale.h>
#include <wchar.h>
#include <ncursesw/ncurses.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

typedef void (*sighandler_t)(int);

void handle_fatal_signal(int signum)
{
    if (false) {
        endwin();       // finalize screen, but assertion-failed messages are also erased
    } else {
        noraw();
        nocbreak();
        echo();
        nonl();
        curs_set(1);
    }

    //char msg[]="got fatal signal\r\n";
    //write(STDERR_FILENO, msg, strlen(msg));

    // re-raise signal
    signal(signum, SIG_DFL);
    kill(getpid(), signum);
}

void minilib_ncurses_init_signal_handlers()
{
    // https://man7.org/linux/man-pages/man7/signal.7.html
    // signals whose action =~ /Core|Term/ && standard =~ /P[0-9]+/
    int fatal_signals[] = {
        SIGABRT, SIGALRM, SIGBUS, SIGFPE, SIGHUP, SIGILL, SIGINT, SIGKILL, SIGPIPE, 
        SIGPOLL, SIGPROF, SIGQUIT, SIGSEGV, SIGSYS, SIGTERM, SIGTRAP, SIGUSR1, SIGUSR2, 
        SIGVTALRM, SIGXCPU, SIGXFSZ, 
    };
    for (int i = 0; i < sizeof(fatal_signals) / sizeof(fatal_signals[0]); i++) {
        // TODO: better to use sigaction(2)
        int signum = fatal_signals[i];
        sighandler_t old_handler = signal(signum, handle_fatal_signal);
        if (old_handler == SIG_ERR) {
            perror("signal");
        }
    }
}

void minilib_ncurses_initialize()
{
    setlocale(LC_ALL, "");  // enable unicode

    initscr();      // init screen
    
    minilib_ncurses_init_signal_handlers();     // setup signal handlers

    noecho();       // no echo back
    curs_set(0);    // set cursor invisible
    cbreak();       // disable line buffering on input
    keypad(stdscr, TRUE);   // enable function keys (arrow keys etc.)

    //erase();        // clear screen

    // initialize colors
    start_color();
    /*
    init_color(COLOR_BLACK, 0, 0, 0);
    init_color(COLOR_RED, 255, 0, 0);
    init_color(COLOR_GREEN, 0, 255, 0);
    init_color(COLOR_YELLOW, 255, 255, 0);
    init_color(COLOR_BLUE, 0, 0, 255);
    init_color(COLOR_MAGENTA, 255, 0, 255);
    init_color(COLOR_CYAN, 0, 255, 255);
    init_color(COLOR_WHITE, 255, 255, 255);
    */

    //init_pair(0, COLOR_BLACK, COLOR_BLACK); // cannot redefine
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void minilib_ncurses_finialize()
{
    endwin();       // finalize screen
}

int minilib_ncurses_err()
{
    return ERR;
}

WINDOW* minilib_ncurses_get_standard_window()
{
    return stdscr;
}

int minilib_ncurses_get_window_size(WINDOW* win)
{
    int w, h;
    // NOTE getmaxyx() is a macro, so w and h are not passed as pointers
    // and it always succeeds
    getmaxyx(win, h, w);
    return (w & 0xffff) << 16 | (h & 0xffff);
}

int minilib_ncurses_draw_border(WINDOW* win)
{
    return box(win, ACS_VLINE, ACS_HLINE);
}

int minilib_ncurses_get_max_colors()
{
    return COLORS;
}

int minilib_ncurses_get_max_color_pairs()
{
    return COLOR_PAIRS;
}
