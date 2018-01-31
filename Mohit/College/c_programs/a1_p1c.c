#include<stdio.h>
#include<math.h>

int main(){
    int i,n,flag=0;
    printf("input a number:\n");
    scanf("%d",&n);
    if(n==1){
        printf("number is niether composite nor prime");
        return 0;
    }
    for (i=2; i<=sqrt(n); i++) {
        if(n%i==0){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("number is composite");
    }
    else{
        printf("number is prime");
    }
    return 0;
}
