#include <stdlib.h>
#include <stdio.h>
//#include <string.h>
#include <mysql.h>

int main(int argc, char *argv[])
{
    MYSQL my_conn;
    int res;

    mysql_init(&my_conn);
    if (mysql_real_connect(&my_conn, "localhost", "rick","mysql", "foo", 0, NULL, 0))
    {
        printf("Connection success\n");
        //mysql_close(&my_conn);
        char tmpSql[] = "UPDATE children SET age = 4 WHERE fname = 'Ann'";
        //res = mysql_query(&my_conn, tmpSql.c_str());
        res = mysql_query(&my_conn, tmpSql);

        if (!res)
        {
            printf("Updated %lu rows\n", (unsigned long)mysql_affected_rows(&my_conn));
        }
        else
        {
            fprintf(stderr, "Update error %d: %s\n",
                    mysql_errno(&my_conn), mysql_error(&my_conn));
        }

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
