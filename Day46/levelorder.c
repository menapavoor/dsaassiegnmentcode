#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// create node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// queue for BFS
struct Node* queue[100];
int front = 0, rear = -1;

// enqueue
void enqueue(struct Node* node)
{
    queue[++rear] = node;
}

// dequeue
struct Node* dequeue()
{
    return queue[front++];
}

// check empty
int isEmpty()
{
    return front > rear;
}

// level order traversal
void levelOrder(struct Node* root)
{
    if(root == NULL)
        return;

    enqueue(root);

    while(!isEmpty())
    {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);

        if(temp->left != NULL)
            enqueue(temp->left);

        if(temp->right != NULL)
            enqueue(temp->right);
    }
}

int main()
{
    int n;
    scanf("%d",&n);

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

    // connect nodes
    for(int i=0;i<n;i++)
    {
        if(nodes[i] != NULL)
        {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    levelOrder(nodes[0]);

    return 0;
}