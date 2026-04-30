#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

// create node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* adj[MAX];
int indegree[MAX];

// queue
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x)
{
    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    // initialize
    for(int i = 0; i < n; i++)
    {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    // input edges
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        indegree[v]++; // count indegree
    }

    // push nodes with indegree 0
    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;

    while(front <= rear)
    {
        int v = dequeue();
        printf("%d ", v);
        count++;

        struct Node* temp = adj[v];

        while(temp != NULL)
        {
            indegree[temp->data]--;

            if(indegree[temp->data] == 0)
                enqueue(temp->data);

            temp = temp->next;
        }
    }

    if(count != n)
        printf("\nNOT POSSIBLE");

    return 0;
}