#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

void enQueue(char student_name[], struct course *c_data)
{
    struct courseque *temp = (struct courseque *)malloc(sizeof(struct courseque));
    strcpy(temp->student_name, student_name);
    temp->previous = NULL;
    temp->nxt = NULL;
    struct courseque *cur = isEmptyQueue(c_data);
    if (!cur) 
    {
        c_data->waitList = temp;
    }
    else
    {
        while (cur->nxt)
        {
            cur = cur->nxt;
        }
        cur->nxt = temp;
        temp->previous
 = cur;
    }
    printf("\nStudent %s is entered into waiting list of course %s", student_name, c_data->code);
    return;
}

int deQueue(char *student_name, struct course *c_data)
{
    struct courseque *cur = isEmptyQueue(c_data);
    if (!cur)
    { 
        return 0;
    }
    strcpy(student_name, cur->student_name);

    if (!cur->nxt)
    { 
        c_data->waitList = cur->nxt;
    }
    else
    { 
        c_data->waitList = cur->nxt;
        cur->nxt->previous
 = NULL;
    }
    free(cur);
    return 1;
}

struct courseque *isEmptyQueue(struct course *c_data)
{
    return c_data->waitList;
}