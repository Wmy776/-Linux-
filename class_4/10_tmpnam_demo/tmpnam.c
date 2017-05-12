#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tmpname[L_tmpnam];
    char *filename;
    FILE *tmpfp;
    filename = tmpnam(tmpname);
    printf("Temporart file name is :%s\n",filename);
    tmpfp = tmpfile();
    if(tmpfp)
        printf("Opened a tmporary file OK\n");
    else 
        perror("tmpfile");
    return 0;
}
