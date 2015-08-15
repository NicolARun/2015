#include <stdlib.h>
#include <stdio.h>

#include <mysql.h>

int main(int argc, char *argv[])
{
    MYSQL my_conn;

    mysql_init(&my_conn);
    if (mysql_real_connect(&my_conn, "localhost", "rick","errorpassword", "foo", 0, NULL, 0))
    {
        printf("Connection success\n");
        mysql_close(&my_conn);
    }
    else
    {
        fprintf(stderr, "Connection failed\n");
        if (mysql_errno(&my_conn))
        {
            fprintf(stderr, "Connection error %d: %s\n",
                    mysql_errno(&my_conn), mysql_error(&my_conn));
        }
    }
    return EXIT_SUCCESS;
}
