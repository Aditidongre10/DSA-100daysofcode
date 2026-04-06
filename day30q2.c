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

// Reverse linked list
struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;

    while (curr != NULL) {
        struct Node* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// Add two reversed lists
struct Node* add(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* temp = &dummy;
    dummy.next = NULL;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        temp->next = createNode(sum % 10);
        temp = temp->next;
    }

    return dummy.next;
}

// Main function to add numbers (forward order)
struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    // Step 1: Reverse both lists
    l1 = reverse(l1);
    l2 = reverse(l2);

    // Step 2: Add them
    struct Node* result = add(l1, l2);

    // Step 3: Reverse result
    return reverse(result);
}