#include<stdio.h>

long factorial(long p);

int main()
{
 long i,p,k;

 printf("Enter the number whose factorial is to be calculated\n");
 scanf("%d",&p);

 if(p<0)
  printf("The factorial of negative number does not exist\n");
 else if(p==0)
  printf("The factorial of 0 is 1\n");
 else
 {k=factorial(p);
 printf("The factorial of %d is %d",p,k);
 }
 getch();
 return 0;

}

long factorial(long p)
{
  long i,sum=1;
 for(i=1;i<=p;i++)
 {sum=sum*i;}
 return(sum);

}
