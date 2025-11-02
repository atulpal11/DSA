/* 7. ​Write a program to store following numbers with table size 10 using Hashing 
129, 115, 161, 136, 212, 553, 914, 307, 608 */

// ...existing code...
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hash_table[TABLE_SIZE];

int hash_func(int key) {
    return key % TABLE_SIZE;
}

int insert_linear(int key) {
    int idx = hash_func(key);
    int start = idx;
    do {
        if (hash_table[idx] == EMPTY) {
            hash_table[idx] = key;
            return 1; // inserted
        }
        idx = (idx + 1) % TABLE_SIZE;
    } while (idx != start);
    return 0; // table full
}

void print_table(void) {
    printf("Hash table (index : value)\n");
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (hash_table[i] == EMPTY)
            printf("%2d : --\n", i);
        else
            printf("%2d : %d\n", i, hash_table[i]);
    }
}

int main(void) {
    int keys[] = {129, 115, 161, 136, 212, 553, 914, 307, 608};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < TABLE_SIZE; ++i) hash_table[i] = EMPTY;

    for (int i = 0; i < n; ++i) {
        if (!insert_linear(keys[i])) {
            printf("Failed to insert %d: table full\n", keys[i]);
        }
    }

    print_table();
    return 0;
}