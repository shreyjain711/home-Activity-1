#include<stdio.h>

int rec(int p);

int main()
{int i,p,k;

 printf("Enter the number whose factorial is to be calculated\n");
 scanf("%d",&p);

 if(p<0)
  printf("The factorial of negative number does not exist\n");
 else if(p==0)
  printf("The factorial of 0 is 1\n");
 else
 {k=rec(p);
 printf("The factorial of %d is %d",p,k);
 }
 getch();
 return 0;

}

int rec(int p)
{int i,j;
 if(p==1)
    return(1);
 else
    i=p*rec(p-1);

 return(i);

}
