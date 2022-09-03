#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

static int regList_Count(struct course_Reg_List *regList)
{
    int count = 0;
    while (regList)
    {
        count++;
        regList = regList->nextstudent;
    }
    return count;
}

void insert(char course_name[], char student_name[], struct course *arr[], int n) // prog2
{
    int i = 0;
    for (; i < n; i++) 
    {
        if (!strcmp(arr[i]->code, course_name))
        {
            break;
        }
    }
    if (i == n)
    {
        printf("\nNo course found!");
        return;
    }
    if (!arr[i]->maxLimit)
    {
        printf("\nNo registrations for the course %s", course_name);
        return;
    }
    if (!(regList_Count(arr[i]->regList) <
          arr[i]->maxLimit)) 
    {
        enQueue(student_name, arr[i]); 
        return;
    }

    struct course_Reg_List *temp =
        (struct course_Reg_List *)malloc(sizeof(struct course_Reg_List));
    strcpy(temp->student_name, student_name);
    struct course_Reg_List *cur, *prev;
    cur = prev = arr[i]->regList;
    if (!cur || (strcmp(student_name, cur->student_name) < 0))
    { 
        temp->nextstudent = cur;
        arr[i]->regList = temp;
    }
    else 
    {
        while (cur && strcmp(student_name, cur->student_name) > 0) 
        {
            prev = cur;
            cur = cur->nextstudent;
        }
        temp->nextstudent = cur;
        prev->nextstudent = temp;
    }
    printf("\nStudent %s registered for the course %s successfully.", student_name, course_name);
    return;
}

void delete (char course_name[], char student_name[], struct course *arr[], int n)
{
    int i = 0, deQueFlag = 0;
    for (; i < n; i++) 
    {
        if (!strcmp(arr[i]->code, course_name))
        {
            break;
        }
    }
    if (i == n)
    {
        printf("\nNo ourse found!!");
        return;
    }
    if (!arr[i]->regList)
    {
        printf("\nNo students listed for the course %s", course_name);
        return;
    }
    struct course_Reg_List *cur;
    struct course_Reg_List *prev;
    cur = prev = arr[i]->regList;
    if (!strcmp(cur->student_name, student_name))
    { 
        arr[i]->regList = cur->nextstudent;
        printf("\nStudent %s deleted from the course %s", student_name, course_name);
        free(cur);
        deQueFlag = deQueue(student_name, arr[i]);
        if (deQueFlag)
        {
            printf("\n\nin deQueFlag of dequeue %s", student_name);
            insert(course_name, student_name, arr, n);
        }
        return;
    }
    cur = cur->nextstudent;
    while (cur) 
    {
        if (!strcmp(cur->student_name, student_name))
        {
            prev->nextstudent = cur->nextstudent;
            free(cur);
            printf("\nStudent %s deleted from the course %s", student_name, course_name);
            deQueFlag = deQueue(student_name, arr[i]);
            if (deQueFlag)
                insert(course_name, student_name, arr, n);
            return;
        }
        prev = cur;
        cur = cur->nextstudent;
    }

    printf("\n%s has not registered to the course %s", student_name, course_name);
    return;
}