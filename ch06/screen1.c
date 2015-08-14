#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

int main()
{
    initscr();

    move(5,15);
    printw("%s", "Hello World");
    move(6,15);
    printw("%d",42);
    refresh();

    sleep(2);

    endwin();
    exit(EXIT_SUCCESS);
}
