#include<stdio.h>
int leap(int);
void display(int,int);
void main()
{
      int year,month;
   printf("enter year,month:");
  scanf("%d%d",&year,&month);
    display(month,year);
  }

void display(month,year)
  {
  int td[12];
  int j,i,q=0,p;

  p= leap(year);
  int day[12]={31,p+28,31,30,31,30,31,31,30,31,30,31};
  int s=0;
  td[0]=0;
  for(i=0;i<=10;i++)
  {
      s=s+day[i];
      td[i+1]=s;
  }

  for(i=1;i<=year-1900;i++)
  {
      q=q+leap(year-i);
  }
  i=td[month-1]+(year-1900)*365+q;
  j=i%7;
  printf("\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t %d/%d\n",month,year);
printf("MON\tTUE\tWED\tTHU\tFRI\tSAT\tSUN\n");
int z;
for(z=1;z<=j;z++)
printf("\t");
for(i=1;i<=day[month-1];i++)
{
    printf("%d\t",i);
    if((i+j)%7==0)
        printf("\n");
}

    while(1)
    {
         int ch;
         ch=getch();
        switch(ch)
        {
         case 72:
            year=year+1;
            display(month,year);
            break;
         case 80:
            year=year-1;
            display(month,year);
            break;
         case 75:
            month=month-1;
            if(month<1)
            {
                month=12;
                year=year-1;
            }
                display(month,year);
                break;
         case 77:
            month=month+1;
            if(month>12)
            {
                month=1;
                year=year+1;

            }
                display(month,year);
                break;
         case 27:
            exit(0);
        }

    }
}
int leap(int p)
{ int x;
  if(p%4!=0)
   x=0;
  else
  {
    if(p%100!=0)
    x=1;
    else
    {
      if(p%400!=0)
      x=0;
      else
      x=1;
    }

  }

  return(x);
}
