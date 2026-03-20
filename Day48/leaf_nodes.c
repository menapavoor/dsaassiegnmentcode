#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Count leaf nodes
int countLeaf(struct Node* root)
{
    if (root == NULL)
        return 0;

    // leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    struct Node* nodes[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Create nodes
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    // Connect nodes
    for (int i = 0; i < n; i++)
    {
        if (nodes[i] != NULL)
        {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < n)
                nodes[i]->left = nodes[left];

            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }

    printf("%d", countLeaf(nodes[0]));

    return 0;
}