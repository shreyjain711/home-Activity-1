#include <stdio.h>
int main()
{
   int num;
   FILE *fptr;
   if ((fptr = fopen("C:\\program.txt","r")) == NULL){
       printf("Error! opening file");
       exit(1);
   }
   fclose(fptr);
   return 0;
}
