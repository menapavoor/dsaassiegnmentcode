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
int recStack[MAX];

// DFS for cycle detection
int dfs(int v)
{
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];

    while(temp != NULL)
    {
        int u = temp->data;

        if(!visited[u] && dfs(u))
            return 1;

        else if(recStack[u])
            return 1;

        temp = temp->next;
    }

    recStack[v] = 0; // remove from recursion stack
    return 0;
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
        recStack[i] = 0;
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

    int hasCycle = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(dfs(i))
            {
                hasCycle = 1;
                break;
            }
        }
    }

    if(hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}