#include <stdlib.h>
#include <stdio.h>
//#include <string.h>
#include <mysql.h>

int main(int argc, char *argv[])
{
    MYSQL my_conn;
    MYSQL_RES *res_ptr;
    MYSQL_ROW sqlrow;
    int res;

    mysql_init(&my_conn);
    if (mysql_real_connect(&my_conn, "localhost", "rick","mysql", "foo", 0, NULL, 0))
    {
        printf("Connection success\n");
        //mysql_close(&my_conn);
        char tmpSql[] = "INSERT INTO children(fname, age) VALUES ('Robert',7)";
        //res = mysql_query(&my_conn, tmpSql.c_str());
        res = mysql_query(&my_conn, tmpSql);

        if (!res)
        {
            printf("Inserted %lu rows\n", (unsigned long)mysql_affected_rows(&my_conn));
        }
        else
        {
            fprintf(stderr, "Insert error %d: %s\n",
                    mysql_errno(&my_conn), mysql_error(&my_conn));
        }

        res = mysql_query(&my_conn, "SELECT LAST_INSERT_ID()");
        if (res)
        {
            printf("SELECT error: %s\n", mysql_error(&my_conn));
        }
        else
        {
            res_ptr = mysql_use_result(&my_conn);
            if (res_ptr)
            {
                while ((sqlrow = mysql_fetch_row(res_ptr)))
                {
                    printf("We inserted childno %s\n", sqlrow[0]);
                }
                mysql_free_result(res_ptr);
            }
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
