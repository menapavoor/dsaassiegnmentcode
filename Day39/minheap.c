#include <stdio.h>
#include <string.h>

#define SIZE 100

int heap[SIZE];
int n = 0;

// swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// insert operation
void insert(int x) {
    if (n == SIZE)
        return;

    heap[n] = x;
    heapifyUp(n);
    n++;
}

// extract minimum
void extractMin() {
    if (n == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);
    heap[0] = heap[n - 1];
    n--;
    heapifyDown(0);
}

// peek minimum
void peek() {
    if (n == 0)
        printf("-1\n");
    else
        printf("%d\n", heap[0]);
}

int main() {
    int N, x;
    char op[20];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "extractMin") == 0) {
            extractMin();
        }
        else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}