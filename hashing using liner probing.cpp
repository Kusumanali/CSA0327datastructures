#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

// Initialize hash table with -1
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using Linear Probing
void insert(int key) {
    int index = hash(key);

    if (hashTable[index] == -1) {
        hashTable[index] = key;
        return;
    }

    // Linear probing
    int i = (index + 1) % SIZE;
    while (i != index) {
        if (hashTable[i] == -1) {
            hashTable[i] = key;
            return;
        }
        i = (i + 1) % SIZE;
    }

    printf("Hash table is full! Cannot insert %d\n", key);
}

// Search using Linear Probing
int search(int key) {
    int index = hash(key);

    if (hashTable[index] == key)
        return index;

    int i = (index + 1) % SIZE;
    while (i != index) {
        if (hashTable[i] == key)
            return i;
        if (hashTable[i] == -1)
            return -1;
        i = (i + 1) % SIZE;
    }

    return -1;
}

// Display hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("Index %d : EMPTY\n", i);
        else
            printf("Index %d : %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice, key;
    init();

    while (1) {
        printf("\n--- Hashing Using Linear Probing ---\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int pos = search(key);
                if (pos == -1)
                    printf("Key %d not found!\n", key);
                else
                    printf("Key %d found at index %d\n", key, pos);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
