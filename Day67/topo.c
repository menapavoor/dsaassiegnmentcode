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
int visited[MAX];

// stack
int stack[MAX];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

// DFS
void dfs(int v)
{
    visited[v] = 1;

    struct Node* temp = adj[v];

    while(temp != NULL)
    {
        if(!visited[temp->data])
            dfs(temp->data);
        temp = temp->next;
    }

    push(v); // push after visiting children
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

    // input edges (DIRECTED)
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    // call DFS for all nodes
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            dfs(i);
    }

    // print stack (topological order)
    while(top != -1)
    {
        printf("%d ", stack[top--]);
    }

    return 0;
}