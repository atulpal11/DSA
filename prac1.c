#include<stdio.h>

int arr[100];  // Fixed size array
int n;         // Size of array

void getSize() {
    printf("Enter the size of array (0 to 100): ");
    scanf("%d", &n);
}

void inputArray() {
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayArray() {
    if(n == 0) {
        printf("\nArray is empty!");
        return;
    }
    printf("\nArray elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertAtBeginning() {
    if(n >= 100) {
        printf("\nArray is full!");
        return;
    }
    int element;
    printf("\nEnter element to insert at beginning: ");
    scanf("%d", &element);
    
    for(int i = n; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = element;
    n++;
}

void insertAtPosition() {
    if(n >= 100) {
        printf("\nArray is full!");
        return;
    }
    int element, pos;
    printf("\nEnter element to insert: ");
    scanf("%d", &element);
    printf("Enter position (0 to %d): ", n);
    scanf("%d", &pos);
    
    if(pos < 0 || pos > n) {
        printf("\nInvalid position!");
        return;
    }
    
    for(int i = n; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = element;
    n++;
}

void insertAtEnd() {
    if(n >= 100) {
        printf("\nArray is full!");
        return;
    }
    int element;
    printf("\nEnter element to insert at end: ");
    scanf("%d", &element);
    
    arr[n] = element;
    n++;
}

void reverseArray() {
    int temp;
    for(int i = 0; i < n/2; i++) {
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

int main() {
    int choice;
    
    getSize();
    inputArray();
    
    do {
        printf("\n\n-------- ARRAY OPERATIONS --------");
        printf("\n1. Display Array");
        printf("\n2. Insert at Beginning");
        printf("\n3. Insert at Specific Position");
        printf("\n4. Insert at End");
        printf("\n5. Reverse Array");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                displayArray();
                break;
            case 2:
                insertAtBeginning();
                displayArray();
                break;
            case 3:
                insertAtPosition();
                displayArray();
                break;
            case 4:
                insertAtEnd();
                displayArray();
                break;
            case 5:
                reverseArray();
                displayArray();
                break;
            case 6:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while(choice != 6);
    
    return 0;
}