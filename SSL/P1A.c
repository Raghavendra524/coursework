#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct course
{
    char code[10];
    char name[10];
    int credit;
    int maxLimit;
    struct bst *regList;
};

struct bst{
    struct bst *parent;
    struct bst *left;
    char *std_name;
    struct bst *right;
};

void create_List(char[]);
void insert(char std_name[], int n, struct course *arr[], char course_name);
void delete(char std_name[], int n, struct course *arr[], char course_name);
FILE *c_ptr;
struct course *arr[10];
int n=0;

int main(int argc, char **args){
    
    char name[10];
    create_List(args[1]);



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
    while (fscanf(c_ptr, "%s %s %d %d",
                  arr[i]->code,
                  arr[i]->name,
                  &arr[i]->credit,
                  &arr[i]->maxLimit) != EOF)
    {
        arr[++i] = (struct course *)malloc(sizeof(struct course));
        arr[i]->regList = NULL;
    }
    n = i;
    free(arr[i]);
    fclose(c_ptr);
    return;
}



void insert(char std_name[], int n, struct course *arr[], char course_name){

    int i=0;
    for(i=0 ; i<n ; i++){
         if (!strcmp(arr[i]->name, course_name))
        {
            break;
        }

    }

    if(i==n){
        printf("\n No course found!!");
        return;
    }

    struct bst *head=(struct bst*)malloc(sizeof(struct bst));
    strcpy(head->std_name,std_name);
    head->left = head->right = head->parent = NULL;
    struct bst *cur = arr[i]->regList;

    if(!cur){
        arr[i]->regList = head;
        cur = arr[i]->regList;
    }
     
    while(cur){

        while(!strcmp(cur->std_name,std_name)||(!strcmp(cur->std_name,std_name)>0)){
            if(cur->left==NULL){
                head->parent = cur;
                cur->left = head;
                break;
            }
            cur = cur->left;

        }
        while(!(strcmp(cur->std_name,std_name)<0)){
            if(cur->right==NULL){
                head->parent = cur;
                cur->right = head;
                break;
            }
            cur = cur->right;

        }
    
    }
    printf("\nStudent %s registered for the course %s successfully.", std_name, course_name);
    return;

}


void delete(char std_name[], int n, struct course *arr[], char course_name){
    int i=0;
    for(i=0 ; i<n ; i++){
         if (!strcmp(arr[i]->name, course_name))
        {
            break;
        }

    }

    if(i==n){
        printf("\n No course found!!");
        return;
    }

    if (!arr[i]->regList)
    {
        printf("\nNo students listed for the course %s", course_name);
        return;
    }

    struct bst *cur = arr[i]->regList;

    if(!cur->left && !cur->right && !cur->parent){
        
        if(!strcmp(cur->std_name,std_name)){
           
            arr[i]->regList = NULL;
            free(cur);
            printf("\nStudent %s deleted from the course %s", std_name, course_name);
            return;
        }

    }

    while(cur){

        while(!strcmp(cur->std_name,std_name)>0){

            cur = cur->left;
            if(!strcmp(cur->std_name,std_name)){

                if(!cur->left && !cur->right){
                    free(cur);
                    printf("\nStudent %s deleted from the course %s", std_name, course_name);
                    return;
                }
                else if(!cur->right && cur->left){
                    cur->parent->left = cur->left;
                    cur->left->parent = cur->parent;
                    free(cur);
                    printf("\nStudent %s deleted from the course %s", std_name, course_name);
                    return;
                }
                else if(cur->right && !cur->left){
                    cur->parent->left = cur->right;
                    cur->right->parent = cur->parent;
                    free(cur);
                    printf("\nStudent %s deleted from the course %s", std_name, course_name);
                    return;
                }
                else if(cur->right && cur->left){
                    struct bst *temp, *temp1;
                    temp = temp1 = cur;
                    while(temp->right){
                        temp = temp->right;
                        if(!temp->right && temp->left){
                            temp->parent->right = temp->left;
                            temp->left->parent = temp->parent;
                            temp1->std_name = temp->std_name;
                            free(temp);
                            printf("\nStudent %s deleted from the course %s", std_name, course_name);
                            return;
                        }
                        else if(!temp->right && !temp->left){
                            temp1->std_name = temp->std_name;
                            free(temp);
                            printf("\nStudent %s deleted from the course %s", std_name, course_name);
                            return;
                        }
                    }
                }
                
            }

        }

    }
}