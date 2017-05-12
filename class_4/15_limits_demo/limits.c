#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int work()
{
    FILE *f;
    int i;
    double x = 4.5;

    f = tmpfile();
    for(i = 0;i < 10000; i ++)
    {
        fprintf(f,"Do some output\n");
        if(ferror(f))
        {
            fprintf(stderr,"Error writing to temporary file \n");
            return 0;
        }
        for(i = 0;i < 1000000;i ++)
            x = log(x*x + 3.21);
    }
}

int main()
{
    struct rusage r_usage;
    struct rlimit r_limit;
    int priority;

    work();
    getrusage(RUSAGE_SELF,&r_usage);
    printf("CPU usage:User = %ld.%06ld,System = %ld.%06ld\n"
                ,r_usage.ru_utime.tv_sec,r_usage.ru_utime.tv_usec
                ,r_usage.ru_stime.tv_sec,r_usage.ru_stime.tv_usec);
    getrlimit(RLIMIT_FSIZE,&r_limit);
    printf("Current FSIZE limit:soft = %ld,hard = %ld\n",
                r_limit.rlim_cur,r_limit.rlim_max);
    r_limit.rlim_cur = 2048;
    r_limit.rlim_max = 4096;
    printf("Setting a 2L file size limit\n");
    setrlimit(RLIMIT_FSIZE,&r_limit);

    work();
    return 0;
}
