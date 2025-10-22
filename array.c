#include<stdio.h>
int main(){
    int n,i;
    printf("Enter the number of Elements you need in an Array:");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("\n Enter the element:");
        scanf("%d",&arr[i]);
    }
    //To Display an Array
    printf("Elements present in the array:");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}