#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    int hd; // horizontal distance
    struct Node *left, *right;
};

// Queue node
struct QNode {
    struct Node* node;
    int hd;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->hd = 0;
    return temp;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i >= n) break;

        // Right child
        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Structure to store vertical order
struct MapNode {
    int hd;
    int values[100];
    int count;
};

// Find index of hd
int findIndex(struct MapNode map[], int size, int hd) {
    for (int i = 0; i < size; i++) {
        if (map[i].hd == hd)
            return i;
    }
    return -1;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct QNode queue[100];
    int front = 0, rear = 0;

    struct MapNode map[100];
    int mapSize = 0;

    queue[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* node = temp.node;
        int hd = temp.hd;

        int idx = findIndex(map, mapSize, hd);
        if (idx == -1) {
            map[mapSize].hd = hd;
            map[mapSize].count = 0;
            idx = mapSize++;
        }

        map[idx].values[map[idx].count++] = node->data;

        if (node->left)
            queue[rear++] = (struct QNode){node->left, hd - 1};

        if (node->right)
            queue[rear++] = (struct QNode){node->right, hd + 1};
    }

    // Sort map by hd
    for (int i = 0; i < mapSize - 1; i++) {
        for (int j = i + 1; j < mapSize; j++) {
            if (map[i].hd > map[j].hd) {
                struct MapNode temp = map[i];
                map[i] = map[j];
                map[j] = temp;
            }
        }
    }

    // Print result
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < map[i].count; j++) {
            printf("%d ", map[i].values[j]);
        }
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}