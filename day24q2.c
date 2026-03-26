#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to remove all occurrences
struct Node* removeElements(struct Node* head, int val) {

    // Step 1: Remove matching nodes at head
    while (head != NULL && head->data == val) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    // Step 2: Traverse rest
    struct Node *curr = head, *prev = NULL;

    while (curr != NULL) {
        if (curr->data == val) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}