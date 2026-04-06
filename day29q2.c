#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int val;
    struct Node* next;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Add two numbers
struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node dummy; // dummy node
    struct Node* temp = &dummy;
    dummy.next = NULL;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        temp->next = createNode(sum % 10);
        temp = temp->next;
    }

    return dummy.next;
}