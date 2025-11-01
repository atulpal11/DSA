// Write a program to demonstrate Bubble sort techniques using arrays: Arrange following roll list of students in ascending order 8, 73, 15, 86, 54, 22, 34, 3, 18, 51
#include<stdio.h>
int main(){
    int arr[10]={8,73,15,86, 54, 22, 34, 3, 18, 51};
    int i,n,temp,j;
    for(i=0;i<10;i++){
        for(j=0;j<10-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\nThe sorted array:");
    for(i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}