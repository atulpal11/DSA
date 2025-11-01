#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to add a new member
struct node* addMember(struct node *head) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter member roll number: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Member added successfully!\n");
    return head;
}

// Function to delete a member
struct node* deleteMember(struct node *head) {
    if (head == NULL) {
        printf("\nClub is empty!\n");
        return NULL;
    }

    int roll;
    printf("\nEnter roll number to delete: ");
    scanf("%d", &roll);

    struct node *temp = head;
    struct node *prev = NULL;

    // If head node itself holds the roll to be deleted
    if (temp != NULL && temp->data == roll) {
        head = temp->next;
        free(temp);
        printf("Member deleted successfully!\n");
        return head;
    }

    // Search for the roll to be deleted
    while (temp != NULL && temp->data != roll) {
        prev = temp;
        temp = temp->next;
    }

    // If roll was not present in linked list
    if (temp == NULL) {
        printf("Member not found!\n");
        return head;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
    printf("Member deleted successfully!\n");
    return head;
}

// Function to count total members
int countMembers(struct node *head) {
    int count = 0;
    struct node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to display all members
void displayMembers(struct node *head) {
    if (head == NULL) {
        printf("\nClub is empty!\n");
        return;
    }

    struct node *temp = head;
    printf("\nMember Roll Numbers: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int choice;

    do {
        printf("\n----- CLUB MEMBERSHIP SYSTEM -----\n");
        printf("1. Add Member\n");
        printf("2. Delete Member\n");
        printf("3. Display All Members\n");
        printf("4. Count Total Members\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = addMember(head);
                break;
            case 2:
                head = deleteMember(head);
                break;
            case 3:
                displayMembers(head);
                break;
            case 4:
                printf("\nTotal number of members: %d\n", countMembers(head));
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 5);

    // Free memory before exiting
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}