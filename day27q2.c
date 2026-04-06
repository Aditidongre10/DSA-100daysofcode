#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Detect and remove cycle
int removeCycle(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return 0;

    struct Node *slow = head, *fast = head;

    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle detected

            // Step 2: Find start of cycle
            slow = head;
            struct Node* prev = NULL;

            // Special case: cycle starts at head
            if (slow == fast) {
                while (fast->next != slow)
                    fast = fast->next;
                fast->next = NULL;
                return 1;
            }

            // General case
            while (slow != fast) {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }

            // Remove cycle
            prev->next = NULL;
            return 1;
        }
    }

    return 0; // No cycle
}