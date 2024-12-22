#include <sys/types.h>
#include <ncurses.h>
#include <unistd.h>
#include <signal.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

void handle_fatal_signal(int signum)
{
    //char newlines[]="\r\n\r\n";
    //write(1, newlines, strlen(newlines));

    if (true) {
        endwin();       // finalize screen, but assertion-failed messages are also erased
    } else {
        noraw();
        nocbreak();
        echo();
        nonl();
        curs_set(1);
    }

    // re-raise signal
    signal(signum, SIG_DFL);
    kill(getpid(), signum);
}

void minilib_ncurses_initialize()
{
    initscr();      // init screen

    signal(SIGABRT, handle_fatal_signal);
    signal(SIGSEGV, handle_fatal_signal);

    noecho();       // no echo back
    curs_set(0);    // set cursor invisible
    cbreak();       // disable line buffering on input
    keypad(stdscr, TRUE);   // enable function keys (arrow keys etc.)

    //erase();        // clear screen

    // initialize colors
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    init_pair(10, COLOR_WHITE, COLOR_BLUE);
}

void minilib_ncurses_finialize()
{
    endwin();       // finalize screen
}

WINDOW* minilib_ncurses_get_default_window()
{
    return stdscr;
}
