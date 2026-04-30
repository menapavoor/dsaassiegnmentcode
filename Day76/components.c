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
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for(int i = 1; i <= n; i++)
    {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // input edges (undirected)
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int count = 0;

    // check all vertices
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}