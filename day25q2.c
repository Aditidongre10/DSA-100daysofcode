#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to find cycle start
struct Node *detectCycle(struct Node *head) {
    struct Node *slow = head, *fast = head;

    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Find start
            struct Node *entry = head;

            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry; // start of cycle
        }
    }

    return NULL; // no cycle
}