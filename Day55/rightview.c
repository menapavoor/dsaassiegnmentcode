#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue
struct Node* queue[MAX];
int front = 0, rear = -1;

void enqueue(struct Node* node)
{
    queue[++rear] = node;
}

struct Node* dequeue()
{
    return queue[front++];
}

int isEmpty()
{
    return front > rear;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    struct Node* nodes[n];

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    // create nodes
    for(int i=0;i<n;i++)
    {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    // connect tree
    for(int i=0;i<n;i++)
    {
        if(nodes[i] != NULL)
        {
            int l = 2*i + 1;
            int r = 2*i + 2;

            if(l < n) nodes[i]->left = nodes[l];
            if(r < n) nodes[i]->right = nodes[r];
        }
    }

    struct Node* root = nodes[0];

    enqueue(root);

    while(!isEmpty())
    {
        int size = rear - front + 1;

        for(int i=0;i<size;i++)
        {
            struct Node* curr = dequeue();

            // last node of level
            if(i == size - 1)
                printf("%d ", curr->data);

            if(curr->left) enqueue(curr->left);
            if(curr->right) enqueue(curr->right);
        }
    }

    return 0;
}