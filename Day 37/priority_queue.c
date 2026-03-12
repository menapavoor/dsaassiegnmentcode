#include <stdio.h>

#define SIZE 100

int pq[SIZE];
int n = 0;

// Insert element
void insert(int x)
{
    if (n == SIZE)
    {
        printf("Queue Overflow\n");
        return;
    }

    int i = n - 1;

    while (i >= 0 && pq[i] > x)
    {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    n++;
}

// Delete highest priority element
void deleteElement()
{
    if (n == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    for (int i = 1; i < n; i++)
        pq[i - 1] = pq[i];

    n--;
}

// Peek element
void peek()
{
    if (n == 0)
        printf("-1\n");
    else
        printf("%d\n", pq[0]);
}

int main()
{
    int N;
    char op[10];
    int x;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%s", op);

        if (op[0] == 'i') // insert
        {
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') // delete
        {
            deleteElement();
        }
        else if (op[0] == 'p') // peek
        {
            peek();
        }
    }

    return 0;
}