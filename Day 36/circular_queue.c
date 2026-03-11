#include <stdio.h>

#define SIZE 100

int queue[SIZE];
int front = -1;
int rear = -1;
int n;

// Enqueue operation
void enqueue(int value)
{
    if ((rear + 1) % n == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % n;
    queue[rear] = value;
}

// Dequeue operation
void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % n;
    }
}

// Display queue
void display()
{
    if (front == -1)
        return;

    int i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % n;
    }
}

int main()
{
    int m, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(value);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        dequeue();
    }

    display();

    return 0;
}