#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
     char name[20];
     char dept[20];
     int id;
     int marks;
};
void write()
{
    FILE *fptr;
    fptr=fopen("accessment.txt","w");
    if(fptr==NULL)
    {
      printf("file opening in error");
      exit(1);
    }
    struct student std={"ram","ece",439,539};
    fwrite(&std,sizeof(struct student),1,fptr);
    fclose(fptr);

}
void read()
{
    FILE *fp;
    struct student std;
    fp=fopen("accessment.txt","r");
    if(fp==NULL)
    {
      printf("file opening in error");
      exit(1);
    }
    while(fread(&std,sizeof(struct student),1,fp)){
       printf("name=%s\n dept=%s\n id=%d\n marks=%d\n",std.name,std.dept,std.id,std.marks);
    }
    fclose(fp);
}
void main()
{
   write();
   read();
}
