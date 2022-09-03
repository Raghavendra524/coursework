#ifndef QUEUE_H_
#define QUEUE_H_
struct course_Reg_List
{
    char student_name[10];
    struct course_Reg_List *nextstudent;
};
struct courseque
{
    char student_name[10];
    struct courseque *previous;
    struct courseque *nxt;
};
struct course
{
    char code[10];
    char name[10];
    int credit;
    int maxLimit;
    struct course_Reg_List *regList;
    struct courseque *waitList;
};
void enQueue(char student_name[], struct course *c_data);
int deQueue(char *student_name, struct course *c_data);
struct courseque *isEmptyQueue(struct course *c_data);

#endif