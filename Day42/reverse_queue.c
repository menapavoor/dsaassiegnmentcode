#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];

int front = 0;
int rear = -1;
int top = -1;

// enqueue
void enqueue(int x)
{
    rear++;
    queue[rear] = x;
}

// dequeue
int dequeue()
{
    int x = queue[front];
    front++;
    return x;
}

// push stack
void push(int x)
{
    top++;
    stack[top] = x;
}

// pop stack
int pop()
{
    int x = stack[top];
    top--;
    return x;
}

int main()
{
    int n, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    // move queue → stack
    while(front <= rear)
    {
        push(dequeue());
    }

    // reset queue
    front = 0;
    rear = -1;

    // move stack → queue
    while(top != -1)
    {
        enqueue(pop());
    }

    // print reversed queue
    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}