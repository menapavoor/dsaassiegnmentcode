#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// adjacency list node
struct Node {
    int v, w;
    struct Node* next;
};

// create node
struct Node* createNode(int v, int w)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = NULL;
    return newNode;
}

struct Node* adj[MAX];

// Min Heap
struct Heap {
    int vertex;
    int dist;
};

struct Heap heap[MAX];
int size = 0;

// swap
void swap(struct Heap* a, struct Heap* b)
{
    struct Heap temp = *a;
    *a = *b;
    *b = temp;
}

// heapify up
void heapifyUp(int i)
{
    while(i && heap[(i-1)/2].dist > heap[i].dist)
    {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// heapify down
void heapifyDown(int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if(right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if(smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// insert into heap
void push(int v, int d)
{
    heap[size].vertex = v;
    heap[size].dist = d;
    heapifyUp(size);
    size++;
}

// extract min
struct Heap pop()
{
    struct Heap root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for(int i = 1; i <= n; i++)
        adj[i] = NULL;

    // input edges
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        struct Node* newNode = createNode(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u, w);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];
    for(int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;
    push(source, 0);

    while(size > 0)
    {
        struct Heap curr = pop();
        int u = curr.vertex;

        struct Node* temp = adj[u];

        while(temp != NULL)
        {
            int v = temp->v;
            int w = temp->w;

            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // print result
    for(int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    return 0;
}