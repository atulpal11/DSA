/*  11. Write a program to simulate the Queues for jobs of an operating system that 
does not use priorities, write functions to add jobs and delete jobs from the queue.  */

// ...existing code...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Job {
    int id;
    char name[64];
    struct Job *next;
};

/* enqueue: add job to rear */
void enqueue(struct Job **front, struct Job **rear) {
    struct Job *node = malloc(sizeof *node);
    if (!node) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter job id: ");
    if (scanf("%d", &node->id) != 1) {
        while (getchar() != '\n');
        free(node);
        printf("Invalid id\n");
        return;
    }
    while (getchar() != '\n'); // consume leftover newline
    printf("Enter job name: ");
    if (fgets(node->name, sizeof node->name, stdin) == NULL) node->name[0] = '\0';
    size_t ln = strlen(node->name);
    if (ln && node->name[ln-1] == '\n') node->name[ln-1] = '\0';
    node->next = NULL;

    if (*rear == NULL) { // empty queue
        *front = *rear = node;
    } else {
        (*rear)->next = node;
        *rear = node;
    }
    printf("Job enqueued: [%d] %s\n", node->id, node->name);
}

/* dequeue: remove job from front */
void dequeue(struct Job **front, struct Job **rear) {
    if (*front == NULL) {
        printf("Queue is empty. No job to delete.\n");
        return;
    }
    struct Job *tmp = *front;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    printf("Job dequeued: [%d] %s\n", tmp->id, tmp->name);
    free(tmp);
}

/* display all jobs from front to rear */
void displayQueue(struct Job *front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Jobs in queue (front -> rear):\n");
    while (front) {
        printf("  [%d] %s\n", front->id, front->name);
        front = front->next;
    }
}

/* count jobs */
int countJobs(struct Job *front) {
    int c = 0;
    while (front) { c++; front = front->next; }
    return c;
}

/* free remaining nodes */
void freeQueue(struct Job *front) {
    while (front) {
        struct Job *t = front;
        front = front->next;
        free(t);
    }
}

int main(void) {
    struct Job *front = NULL, *rear = NULL;
    int choice;

    do {
        printf("\n--- JOB QUEUE (no priorities) ---\n");
        printf("1. Add job (enqueue)\n");
        printf("2. Delete job (dequeue)\n");
        printf("3. Display jobs\n");
        printf("4. Count jobs\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0;
        }

        switch (choice) {
            case 1: enqueue(&front, &rear); break;
            case 2: dequeue(&front, &rear); break;
            case 3: displayQueue(front); break;
            case 4: printf("Total jobs: %d\n", countJobs(front)); break;
            case 5: printf("Exiting...\n"); break;
            default: if (choice != 0) printf("Invalid choice\n");
        }
    } while (choice != 5);

    freeQueue(front);
    return 0;
}
// ...existing code...