#include<stdio.h>

int len(char *p)
{int j=0;
 while(*(p+j)!='\0')
 {j++;}
  return(j);
}

void copy(char *p,char *cpy)
{ int j;
  for(j=0;*(p+j)!='\0';j++)
  {*(cpy+j)=*(p+j);
      }
}

void concatinate(char *p,char *B)
{int j,k=len(p);
 for(j=0;*(B+j)!='\0';j++)
 {*(p+k+j)=*(B+j);
     }
}

int reverse(char *p,char *cpy)
{int m=len(p),k;
 for(k=0;k<m;k++)
 {*(cpy+k) = *(p+m-k-1);
  }
 puts(cpy);

}

int lower(char *p)
{int m,j,k=len(p);
 for(j=0;j<k;j++)
 {m=*(p+j);
  if(m<91)
  {*(p+j)=m+32 ;}

 }
 puts(p);
}

int upper(char *p)
{int m,j,k=len(p);
  for(j=0;j<k;j++)
  {m=*(p+j);
   if(m>96)
   {*(p+j)=m-32;}

  }
 puts(p);
}

int main()
{char p[1000],cpy[1000],B[1000];
 int i,j,k;
 printf("Enter the string Elements\n");
 scanf("%[^\n]s",p);

 printf("\nWhich String Function you wish to use\n");
 printf("1 Length Of String\n2 Copy above String to String cpy\n3 Concatinate String B to above String\n4 Reverse String\n5 Lower Case String\n6 Upper Case String\n");
 printf("Enter the no. corresponding to String function you Wish to Use\n\n");
 scanf("%d",&i);

 if(i>6 || i<1)
    printf("Please Enter the valid number i.e. between 1 to 6");
 switch(i)
{case 1:
    k=len(p);
    printf("%d",k);
    break;

 case 2:
     copy(p,cpy);
     puts(cpy);
     break;

 case 3:
     printf("Enter the elemet of string B to be Concatinated to above string\n");
     fflush(stdin);
     scanf("%[^\n]s",B);
     concatinate(p,B);
     puts(p);
     break;

 case 4:
     reverse(p,cpy);
     break;

 case 5:
     lower(p);
     break;

 case 6:
     upper(p);
     break;

 default:
    break;
}

getch();
return 0;

}










