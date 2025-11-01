//Write a program to demonstrate Insertion sort techniques using arrays: Arrange following roll list of students in ascending order 88, 76, 15, 80, 44, 5,37,1, 28, 65
#include <stdio.h>

int main() {
    int arr[] = {88, 76, 15, 80, 44, 5, 37, 1, 28, 65};
    int n = 10;  // Number of elements
    int i, j, key;

    printf("Original Roll Numbers:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Insertion Sort Algorithm
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("\n\nRoll Numbers in Ascending Order (after Insertion Sort):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}