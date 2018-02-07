#include<stdio.h>
#include<stdlib.h>
int main()
{

	FILE *f;
	char s[80];
	f=fopen("file1.txt","r");
	if(f==NULL);
	{
		puts("cannot open file");
		exit(1);
	}
	while(fgets(s,79,f)!=NULL)
	printf("%s",s);
	printf("\n");
	fclose(f);
	return 0;
}
