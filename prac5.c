/*5. ​Write a program to demonstrate a double linked list: Students can be granted 
membership of the club on request. Store the student roll no. Write functions to 
a) Add and delete the members. 
b) Compute total number of members of club 
c) Display members 
d) Display list in reverse order */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node* addMember(struct node *head) {
    int roll;
    printf("\nEnter member roll number to add: ");
    if (scanf("%d", &roll) != 1) return head;

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return head;
    }
    newnode->data = roll;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("Member added successfully!\n");
    return head;
}

struct node* deleteMember(struct node *head) {
    if (head == NULL) {
        printf("\nClub is empty!\n");
        return NULL;
    }

    int roll;
    printf("\nEnter roll number to delete: ");
    if (scanf("%d", &roll) != 1) return head;

    struct node *temp = head;
    while (temp != NULL && temp->data != roll) temp = temp->next;

    if (temp == NULL) {
        printf("Member not found!\n");
        return head;
    }

    if (temp->prev != NULL) temp->prev->next = temp->next;
    else head = temp->next; // deleting head

    if (temp->next != NULL) temp->next->prev = temp->prev;

    free(temp);
    printf("Member deleted successfully!\n");
    return head;
}

int countMembers(struct node *head) {
    int count = 0;
    struct node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void displayMembers(struct node *head) {
    if (head == NULL) {
        printf("\nClub is empty!\n");
        return;
    }
    printf("\nMembers (forward): ");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayReverse(struct node *head) {
    if (head == NULL) {
        printf("\nClub is empty!\n");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL) temp = temp->next; // go to tail
    printf("\nMembers (reverse): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void freeList(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    struct node *head = NULL;
    int choice;

    do {
        printf("\n----- DOUBLY LINKED LIST CLUB -----\n");
        printf("1. Add Member\n");
        printf("2. Delete Member\n");
        printf("3. Display Members (forward)\n");
        printf("4. Display Members (reverse)\n");
        printf("5. Count Total Members\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            // clear invalid input
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            choice = 0;
        }

        switch (choice) {
            case 1: head = addMember(head); break;
            case 2: head = deleteMember(head); break;
            case 3: displayMembers(head); break;
            case 4: displayReverse(head); break;
            case 5: printf("\nTotal number of members: %d\n", countMembers(head)); break;
            case 6: printf("\nExiting program...\n"); break;
            default: if (choice != 0) printf("\nInvalid choice!\n");
        }
    } while (choice != 6);

    freeList(head);
    return 0;
}