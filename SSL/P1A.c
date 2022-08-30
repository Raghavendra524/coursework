#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct course
{
char code[10];
char name[5];
int credits;
};
int getcredits(struct course *arr[],char code[],int n);
int main(int argc, char *argv[])
{
int n;
FILE *c_file;
c_file = fopen (argv[1], "r");
char c = getc(c_file);
while(c != EOF){
if (c == '\n')    
n+=1;
c = getc(c_file);
}
fclose(c_file);
struct course *arr[n];
for(int i=0;i<n;i++){
arr[i]= (struct course*)malloc(sizeof(struct course));
}
c_file = fopen (argv[1], "r");
if(c_file==NULL){
printf("file not found\n");
exit(1);
}
for(int i=0;i<n;i++)
{
fscanf(c_file, "%s", arr[i]->code);
fscanf(c_file, "%s", arr[i]->name);
fscanf(c_file, "%d", &arr[i]->credits);
}
fclose(c_file);
char s[10];
printf("enter the code to get credits\n");
scanf("%s",s);
int r=getcredits(arr,s,n);
if(r==0){
printf("course enrollmentid not matched\n");
}
else
printf("no of credits for course: %d", r);
return 0;
}
int getcredits(struct course *arr[],char code[],int n)
{
for(int i=0;i<n;i++){
int val= strcmp(arr[i]->code, code);
if(val==0)
return arr[i]->credits;
}
return 0;
}