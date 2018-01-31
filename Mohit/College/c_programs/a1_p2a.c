#include<stdio.h>

int main(){
    int a[10],i=0;
    printf("input ten numbers:\n");
    for (; i<10; i++) {
        scanf("%d",&a[i]);
    }
    printf("here are the numbers you entered:\n");
    for (i=0; i<10; i++) {
        printf("%d\n",a[i]);
    }
    return 0;
}
