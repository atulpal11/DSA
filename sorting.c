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

void displayArray() {
    printf("\nArray elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort() {
    int temp;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort() {
    int min_idx, temp;
    for(int i = 0; i < n-1; i++) {
        min_idx = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void insertionSort() {
    int key, j;
    for(int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int choice;
    
    getSize();
    inputArray();
    
    do {
        printf("\n\n-------- SORTING ALGORITHMS --------");
        printf("\n1. Display Array");
        printf("\n2. Bubble Sort");
        printf("\n3. Selection Sort");
        printf("\n4. Insertion Sort");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                displayArray();
                break;
            case 2:
                bubbleSort();
                printf("\nArray after Bubble Sort:");
                displayArray();
                break;
            case 3:
                selectionSort();
                printf("\nArray after Selection Sort:");
                displayArray();
                break;
            case 4:
                insertionSort();
                printf("\nArray after Insertion Sort:");
                displayArray();
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while(choice != 5);
    
    return 0;
}