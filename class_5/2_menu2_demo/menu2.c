#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char *menu[] = {"a - add new record","d - delete record","q -quit",NULL};

int getchoice(char *greet,char *choices[]);

int main()
{
    int choice = 0;
    if(!isatty(fileno(stdout)))
    {
        fprintf(stderr,"You are not a terminal!\n");
        exit(1);
    }
    do
    {
        choice = getchoice("Please selecte an acntion",menu);
        printf("You have chosen:%c\n",choice);
    }while(choice != 'q');
    exit(0);
}

int getchoice(char *greet,char *choices[])
{
    int chosen = 0;
    int selected;
    char **option;
    do
    {
        printf("Choice:%s\n",greet);
        option = choices;
        while(*option)
        {
            printf("%s\n",*option);
            option ++;
        }
        do
        { 
            selected = getchar();
        }while(selected == '\n');
        printf("selected:%c\n",selected);
        option = choices;
        while(*option)
        {
            if(selected == *option[0])
            {
                chosen = 1;
                break;
            }
            option ++;
        }
        if(!chosen)
            printf("Incorrect choice,select again\n");
    }while(!chosen);
    return selected;
}

