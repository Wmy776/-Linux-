#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    struct tm *tm_ptr,timestruct;
    time_t the_time;
    char buf[256];
    char *result;
    (void)time(&the_time);
    tm_ptr = localtime(&the_time);
    strftime(buf,256,"%A %d %B,%I:%D %p",tm_ptr);
    printf("strftime gives:%s\n",buf);
    strcpy(buf,"Thu 26 July 2007,17:53 will do fine");
    printf("calling strptime with:%s\n",buf);
    tm_ptr = &timestruct;
    result = strptime(buf,"%a %d %b %Y,%R",tm_ptr);
    printf("strptime gives:\n");
    return 0;
}
