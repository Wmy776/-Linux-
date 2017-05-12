#include <stdio.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>

int main()
{
    int nrows,ncolnums;
    setupterm(NULL,fileno(stdout),(int *)0);
    nrows = tigetnum("lines");
    ncolnums = tigetnum("cols");
    printf("This terminal has %d colnmns and %d rows\n",ncolnums,nrows);
    return 0;
}
