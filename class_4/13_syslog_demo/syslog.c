#include <stdio.h>
#include <syslog.h>
#include <stdlib.h>

int main()
{
    FILE *f;

    f = fopen("not_here","r");
    if(!f)
        syslog(LOG_ERR | LOG_USER,"oops - %m\n");
    return 0;
}
