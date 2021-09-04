#include<stdio.h>
#include<stdlib.h>

void main()
{
    FILE *fp;
    char ch,file[10];
    clrscr();
    printf("\nEnter file name:");
    scanf("%s",file);
    fp=fopen(file,"w");   
    if(fp==NULL)   
    {
        printf("\nFile could not open");
        exit(0);
    }
    printf("\npress * to exit\nEnter data: ");
    while(1)
    {
        ch=getche();
        if(ch=='*'){
            break;
        }     
        putc(ch,fp);
    }
    fclose(fp);
    fp = fopen(file, 'r');
    if(fp==NULL){
        printf("\nFile is NULL");
        exit(0);
    }
    ch = fgetc(fp);
    while(ch!=EOF){
        printf("%c", ch);
        ch = fgetc(fp);
    }
    fclose(fp);
}