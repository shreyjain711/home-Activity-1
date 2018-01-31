#include<stdio.h>
int main()
{int i,j,m,n,p,l;

 printf("Enter the row*column of matrix A\n");
 scanf("%d%d",&m,&n);

 printf("Enter the row*column of matrix B\n");
 scanf("%d%d",&p,&l);

 if(m!=p || n!=l)
  printf("Matrix subtraction not possible\n");
 else
 {
 int A[m][n],B[p][l],C[m][n];

 printf("Enter the elemnts of matrix A rowise\n");
 for(i=0;i<m;i++)
 {for(j=0;j<n;j++)
   {scanf("%d",&A[i][j]);}
 }

 printf("Enter the elemnts of matrix B to be subtracted from matrix A rowise\n");
 for(i=0;i<p;i++)
 {for(j=0;j<l;j++)
   {scanf("%d",&B[i][j]);}
 }

 for(i=0;i<m;i++)
 {for(j=0;j<n;j++)
   {C[i][j]=A[i][j]-B[i][j] ;
       }
 }

 printf("The subtraction of matrix B from matrix A is\n");
 for(i=0;i<m;i++)
 {printf("\nRow%d ",i+1);
   for(j=0;j<n;j++)
  {printf("%d ",C[i][j]);
     }
  }
  getch();
 return 0;

 }
}
