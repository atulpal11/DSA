#include<stdio.h>
int arr[100];
int n;

void getSize(){
    printf("Enter the size of array: ");
    scanf("%d", &n);
}

void inputArray() {
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int main(){
    return 0;
}