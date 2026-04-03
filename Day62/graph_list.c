#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    // array of adjacency lists
    struct Node* adj[n];

    // initialize lists
    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    // input edges
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        // add v to u
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // add u to v (undirected)
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    // print adjacency list
    for(int i = 0; i < n; i++)
    {
        printf("%d: ", i);
        struct Node* temp = adj[i];

        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}