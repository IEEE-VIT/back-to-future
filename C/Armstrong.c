// Check if a number is Armstrong number or not

#include<stdio.h>

int isArmstrong(int n){
    int r,sum=0,temp;
    temp=n;
    while(n>0){
        r=n%10;
        sum=sum+(r*r*r);
        n/=10;
    }

    if(temp==sum){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    printf("Enter a number\n");
    scanf("%d",&n);
    int result = isArmstrong(n);
    printf("%d",result);
}