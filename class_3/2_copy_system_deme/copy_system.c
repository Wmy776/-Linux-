#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    char c;
    int in,out;
    in = open("file.in",O_RDONLY);
    out = open("file.out",O_WRONLY | O_CREAT,S_IRUSR | S_IWUSR);
    while(read(in,&c,1) == 1)
        write(out,&c,1);
    exit (0);
}
