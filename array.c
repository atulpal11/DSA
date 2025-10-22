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
    //To reverse the array
    int j,temp;
    for(i=0;i<n;i++){
        for(j=n-1;j>i;j--){
            temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
        }
    }
    //To Display an Array after reversing
    printf("\nElements present in the array:");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}