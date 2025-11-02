// /* 7. ​Write a program to store following numbers with table size 10 using Hashing 
// 129, 115, 161, 136, 212, 553, 914, 307, 608 */

#include <stdio.h>

#define TABLE_SIZE 10

int main() {
    int hashTable[TABLE_SIZE];
    int numbers[] = {129, 115, 161, 136, 212, 553, 914, 307, 608};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // Initialize all slots to -1 (empty)
    for(int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    // Insert numbers using linear probing
    for(int i = 0; i < n; i++) {
        int num = numbers[i];
        int index = num % TABLE_SIZE;

        // Handle collisions
        while(hashTable[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
        }

        hashTable[index] = num;
    }

    // Print the hash table
    printf("Hash Table (Table Size = 10):\n");
    printf("-----------------------------\n");
    for(int i = 0; i < TABLE_SIZE; i++) {
        if(hashTable[i] != -1)
            printf("Index %d -> %d\n", i, hashTable[i]);
        else
            printf("Index %d -> [Empty]\n", i);
    }

    return 0;
}