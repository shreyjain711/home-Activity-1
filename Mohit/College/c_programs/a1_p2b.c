#include<stdio.h>

int main(){
    int i,x,y,a[10];
    printf("input ten numbers:\n");
    scanf("%d",&a[0]);
    x=y=a[0];
    for (i=1; i<10; i++) {
        scanf("%d",&a[i]);
        if (a[i]>x) {
            x=a[i];
        }
        if (a[i]<y) {
            y=a[i];
        }
    }
    printf("the largest number is: %d\nthe smallest number is: %d\n",x,y);
    return 0;
}
