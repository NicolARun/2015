#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int i;
    time_t the_time;
    struct tm *tm_ptr;
    char *ch_time;

    for (i = 1; i <= 10; i++)
    {
        the_time = time((time_t *)0);
        printf("The time is %ld\n", the_time);
    
        //tm_ptr = gmtime(&the_time);
        tm_ptr = localtime(&the_time);
        printf("gmtime gives:\n");

        printf("data: %04d/%02d/%02d\n",
            (tm_ptr->tm_year + 1900), tm_ptr->tm_mon+1, tm_ptr->tm_mday);
        printf("time: %02d:%02d:%02d\n",
            tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);

        ch_time = asctime(tm_ptr);
        printf("%s", ch_time);

        sleep(2);
    }
    exit(0);
}
