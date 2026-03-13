#include <stdio.h>

#define SIZE 100

int deque[SIZE];
int front = -1;
int rear = -1;

// check empty
int empty() {
    return (front == -1);
}

// size of deque
int size() {
    if (empty())
        return 0;
    return rear - front + 1;
}

// push front
void push_front(int value) {
    if (front == 0) {
        printf("Deque Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        front--;
    }

    deque[front] = value;
}

// push back
void push_back(int value) {
    if (rear == SIZE - 1) {
        printf("Deque Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
}

// pop front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

// pop back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

// front element
void getFront() {
    if (empty())
        printf("-1\n");
    else
        printf("%d\n", deque[front]);
}

// rear element
void getBack() {
    if (empty())
        printf("-1\n");
    else
        printf("%d\n", deque[rear]);
}

// display deque
void display() {
    if (empty())
        return;

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);

    display();

    pop_front();
    pop_back();

    display();

    return 0;
}