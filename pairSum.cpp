// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is 
// known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. 
// These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.
// Given the head of a linked list with even length, return the maximum twin sum of the linked list.


#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function prototypes
void calc(ListNode** a, ListNode* b, int* max, bool* flag);
int pairSum(ListNode* head);

void calc(ListNode** a, ListNode* b, int* max, bool* flag) {
    if(!b) return;
    calc(a, b->next, max, flag);
    if(*flag) return;
    if(b->val + (*a)->val > *max) *max = b->val + (*a)->val;
    if((*a)->next == b) *flag = 1;
    *a = (*a)->next;
}

int pairSum(ListNode* head) {
    int max = 0;
    bool flag = 0;
    calc(&head, head, &max, &flag);
    return max;    
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Calculate the pair sum
    int result = pairSum(head);

    // Print the result
    std::cout << "The maximum twin sum is: " << result << std::endl;

    // Clean up the memory
    ListNode* current = head;
    while (current != NULL) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
