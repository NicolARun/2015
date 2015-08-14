#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char tmpname[L_tmpnam];
    char *filename;
    FILE *tmpfp;

    filename = tmpnam(tmpname);

    printf("Temporary file name is: %s\n", filename);
    tmpfp = tmpfile();
    if (tmpfp)
    {
        printf("Opened a temporary file OK\n");
    }
    else
    {
        perror("tmpfile");
    }

    char template[] = "file_TJQ_XXXXXX";
    printf("the template is: %s\n", template);

    char *filename_mk = mktemp(template);
    printf("Temporary file name by mktemp is: %s\n", filename_mk);

    exit(0);
}
