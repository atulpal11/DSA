#include<stdio.h>
int main(){
    int n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int arr[n+1]; // Create array with extra space for insertion
    
    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    // Print original array
    printf("Original array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    // Insert element at beginning
    int element;
    printf("\nEnter element to insert at beginning: ");
    scanf("%d", &element);
    
    // Shift elements to right
    for(i=n; i>0; i--){
        arr[i] = arr[i-1];
    }
    
    // Insert new element at beginning
    arr[0] = element;
    n++; // Increase array size
    
    // Print array after insertion
    printf("Array after insertion: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
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