#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

struct course *arr[10];

void create_List(char[]);
int get_Credits(struct course *[], char[]);

FILE *c_ptr;
int n; 

int main(int argc, char **args)
{
    char code[10], student_Name[20];
    int credit;
    create_List(args[1]);
    int pick = 0;
    while (1)
    {
        printf("\n1.Insert \n2.Delete \n3.Exit");
        printf("\nEnter valid option: ");
        scanf("%d", &pick);
        if (pick == 3)
        {
            break;
        }
        else if (pick != 1 && pick != 2)
        {
            printf("\nInvalid option!\n");
        }
        else
        {
            printf("\nEnter the name of the student: ");
            scanf("%s", student_Name);
            printf("\nEnter the Course code: ");
            scanf("%s", code);
            if (pick == 1)
            {
                insert(code, student_Name, arr, n);
            }
            else if (pick == 2)
            {
                delete (code, student_Name, arr, n);
            }
        }
    }
    return 0;
}

void create_List(char file[])
{
    int i = 0;
    c_ptr = fopen(file, "r");
    if (!c_ptr)
    {
        printf("Error!!, No file Found");
        exit(1);
    }

    arr[i] = (struct course *)malloc(sizeof(struct course));
    arr[i]->regList = NULL;
    arr[i]->waitList = NULL;
    while (fscanf(c_ptr, "%s %s %d %d",
                  arr[i]->code,
                  arr[i]->name,
                  &arr[i]->credit,
                  &arr[i]->maxLimit) != EOF)
    {
        arr[++i] = (struct course *)malloc(sizeof(struct course));
        arr[i]->regList = NULL;
        arr[i]->waitList = NULL;
    }
    n = i;
    free(arr[i]);
    fclose(c_ptr);
    return;
}

int get_Credits(struct course *arr[], char code[])
{
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(arr[i]->code, code))
            return arr[i]->credit;
    }
    return '\0';
}