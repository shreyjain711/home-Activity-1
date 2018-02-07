
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{ 
FILE *fp;
 
char s[80];
fp=fopen("file1.txt","w");
if(fp==NULL) 
{
	puts("cannot open file");
	exit(1);
}
printf("\nEnter a few lines to input in file:\n");
while(strlen(gets(s))>0)
{
	fputs("\n",fp);
	fputs("\n",fp);
 } 
 fclose(fp);
 return 0;
}
 
 
 
 
 
 

