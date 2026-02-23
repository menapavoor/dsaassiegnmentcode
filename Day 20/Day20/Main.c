#include <stdio.h>
#include <stdlib.h>

// Hash map node
typedef struct Node {
    int prefixSum;
    int count;
    struct Node* next;
} Node;

// Simple hash function
int hash(int key, int size) {
    if (key < 0) key = -key;
    return key % size;
}

// Insert or update prefix sum in hash map
void insert(Node** hashTable, int size, int prefixSum) {
    int idx = hash(prefixSum, size);
    Node* curr = hashTable[idx];
    while (curr) {
        if (curr->prefixSum == prefixSum) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->prefixSum = prefixSum;
    newNode->count = 1;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

// Get count of prefixSum from hash map
int getCount(Node** hashTable, int size, int prefixSum) {
    int idx = hash(prefixSum, size);
    Node* curr = hashTable[idx];
    while (curr) {
        if (curr->prefixSum == prefixSum) return curr->count;
        curr = curr->next;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int hashSize = 10007; // prime size for hash table
    Node** hashTable = (Node**)calloc(hashSize, sizeof(Node*));

    int prefixSum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) count++;

        count += getCount(hashTable, hashSize, prefixSum);

        insert(hashTable, hashSize, prefixSum);
    }

    printf("%d\n", count);
    return 0;
}