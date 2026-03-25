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

// Find LCA
struct Node* findLCA(struct Node* root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    struct Node* left = findLCA(root->left, n1, n2);
    struct Node* right = findLCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
        return root;

    return (left != NULL) ? left : right;
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

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(nodes[0], n1, n2);

    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}