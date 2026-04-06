#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
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
int visited[MAX];

// Queue
int queue[MAX];
int front = 0, rear = -1;

// enqueue
void enqueue(int x)
{
    queue[++rear] = x;
}

// dequeue
int dequeue()
{
    return queue[front++];
}

// BFS
void bfs(int start)
{
    enqueue(start);
    visited[start] = 1;

    while(front <= rear)
    {
        int v = dequeue();
        printf("%d ", v);

        struct Node* temp = adj[v];

        while(temp != NULL)
        {
            if(!visited[temp->data])
            {
                enqueue(temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
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
        visited[i] = 0;
    }

    // input edges
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        // undirected graph
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int start;
    scanf("%d", &start);

    bfs(start);

    return 0;
}