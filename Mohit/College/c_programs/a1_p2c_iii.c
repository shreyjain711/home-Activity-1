#include<stdio.h>
#include<conio.h>

int main()
{
 int A[10][10],B[10][10],C[10][10];
 int m,n,l,p,i,j,k,sum=0;
 printf("Enter the row*column dimension of matrix A\n");
 scanf("%d%d",&m,&n);
 printf("Enter the row*column dimension of matrix B\n");
 scanf("%d%d",&l,&p);

 if(n!=l)
    printf("The Matrix multiplication is not possible\n");
 else
{
  printf("Enter the elements of matrix A rowise\n");
  for(i=0;i<m;i++)
 {for(j=0;j<n;j++)
  {scanf("%d",&A[i][j]);}
 }

  printf("Enter the elements of matrix B rowise\n");
  for(i=0;i<l;i++)
  {for(j=0;j<p;j++)
   {scanf("%d",&B[i][j]);}
  }



    for(i=0;i<m;i++)
    {for(j=0;j<p;j++)
      {sum=0;
       for(k=0;k<n;k++)
       {sum=sum + A[i][k]*B[k][j];}
       C[i][j]=sum;}
    }
    printf("A*B-\n");
    for(i=0;i<m;i++)
    {printf("R%d ",i+1);
     for(j=0;j<p;j++)
     {printf("%d ",C[i][j]);}
     printf("\n");
    }
}
getch();
return 0;
}
