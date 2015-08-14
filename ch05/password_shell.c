#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

#define PASSWORD_LEN 8

int main()
{
    struct termios initialrsettings, newrsettings;
    char password[PASSWORD_LEN + 1];
    
    // tcgetattr: init the termios struct of fn stdin
    tcgetattr(fileno(stdin), &initialrsettings);

    newrsettings = initialrsettings;
    // clear the bit flag ECHO
    newrsettings.c_lflag &= ~ECHO;

    printf("Enter password: ");

    if (tcsetattr(fileno(stdin), TCSAFLUSH, &newrsettings) != 0)
    {
        fprintf(stderr, "Could not set attributes\n");
    }
    else
    {
        fgets(password, PASSWORD_LEN, stdin);
        tcsetattr(fileno(stdin), TCSANOW, &initialrsettings);
        fprintf(stdout, "\nYou entered %s\n", password);
    }
    exit(0);
}
