#include <stdio.h>
#include <stdlib.h>

#define MAX 1000  // maximum stack size

typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Initialize stack
void init(Stack *s) {
    s->top = -1;
}

// Push operation
void push(Stack *s, int val) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++s->top] = val;
}

// Pop operation
void pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return;
    }
    s->top--;
}

// Print stack from top to bottom
void printStack(Stack *s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    init(&s);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        push(&s, val);
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop(&s);
    }

    printStack(&s);

    return 0;
}