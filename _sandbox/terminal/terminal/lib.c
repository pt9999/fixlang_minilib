#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

typedef void (*sighandler_t)(int);

uint64_t caught_signals = 0;

void handle_signal(int signo)
{
    caught_signals |= (uint64_t) 1 << signo;
    signal(signo, &handle_signal);
}

int minilib_terminal_init_signal_handler()
{
    sighandler_t ret;

    ret = signal(SIGWINCH, &handle_signal);
    if (ret == SIG_ERR) {
        return -1;
    }
    return 0;
}

/*
    Returns non-zero if the window size has been changed.
    The changed status will be reset.
*/
int minilib_terminal_check_window_size_changed()
{
    uint64_t mask = (uint64_t) 1 << SIGWINCH;
    uint64_t result = caught_signals & mask;
    caught_signals &= ~mask;

    return result != 0;
}
