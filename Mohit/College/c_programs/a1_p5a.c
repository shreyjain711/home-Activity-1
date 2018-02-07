#include<stdio.h>

void fib(int n);

int main()
{int n;

 printf("Enter the no. of elements of fibonacci series\n");
 scanf("%d",&n);

 printf("The first %d members of fiboncci series are \n",n);

 printf("0 ");
 fib(n);
 getch();
 return 0;
}

void fib(int n)
{int i,first=0,second=1,next=1,count=1;

 for(i=0;count<=n;i++)
 {printf(" %d",next);
  next=first+second;
  first=second;
  second=next;

  count++;

  if(count==n)
    break;
  }
}
