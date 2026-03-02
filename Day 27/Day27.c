#include <stdio.h>
#include <stdlib.h>

// Define singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at tail
struct Node* insertAtTail(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to calculate length of list
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection point (by value)
struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    struct Node* ptrA = headA;
    struct Node* ptrB = headB;

    // Advance longer list
    if (lenA > lenB) {
        int diff = lenA - lenB;
        for (int i = 0; i < diff; i++) {
            ptrA = ptrA->next;
        }
    } else {
        int diff = lenB - lenA;
        for (int i = 0; i < diff; i++) {
            ptrB = ptrB->next;
        }
    }

    // Traverse together
    while (ptrA != NULL && ptrB != NULL) {
        if (ptrA->data == ptrB->data) {
            return ptrA; // intersection found
        }
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    return NULL; // no intersection
}

int main() {
    int n, m;
    scanf("%d", &n);

    struct Node* headA = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        headA = insertAtTail(headA, val);
    }

    scanf("%d", &m);
    struct Node* headB = NULL;
    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        headB = insertAtTail(headB, val);
    }

    struct Node* intersection = getIntersectionNode(headA, headB);

    if (intersection != NULL) {
        printf("%d\n", intersection->data);
    } else {
        printf("No Intersection\n");
    }

    return 0;
}