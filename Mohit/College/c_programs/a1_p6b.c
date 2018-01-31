#include<stdio.h>

#define AREA(x)(3.14*x*x)

int main()
{int r;
 float area;

 printf("Enter the radius of circle whose area is to be calculated\n");
 scanf("%d",&r);

 area=AREA(r);

 printf("The area of circle of radii %d is %f",r,area);
 getch();
 return 0;
}
