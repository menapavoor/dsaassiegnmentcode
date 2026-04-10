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

// DFS function
int dfs(int v, int parent)
{
    visited[v] = 1;

    struct Node* temp = adj[v];

    while(temp != NULL)
    {
        int u = temp->data;

        if(!visited[u])
        {
            if(dfs(u, v))
                return 1;
        }
        else if(u != parent)
        {
            return 1; // cycle found
        }

        temp = temp->next;
    }

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
    }

    // input edges (UNDIRECTED)
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

    int hasCycle = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, -1))
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