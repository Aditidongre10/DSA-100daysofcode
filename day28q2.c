#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int val;
    struct Node* next;
};

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

// Check palindrome
int isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return 1;

    struct Node *slow = head, *fast = head;

    // Step 1: Find middle
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    struct Node* secondHalf = reverse(slow->next);

    // Step 3: Compare both halves
    struct Node* firstHalf = head;
    struct Node* temp = secondHalf;

    while (temp != NULL) {
        if (firstHalf->val != temp->val)
            return 0; // false

        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    return 1; // true
}