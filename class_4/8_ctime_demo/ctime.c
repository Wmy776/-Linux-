#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    time_t timeval;
    (void)time(&timeval);
    printf("The date is %s\n",ctime(&timeval));
    return 0;
}
