// Given the head of a singly linked list, group all the nodes with odd indices together 
// followed by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// Note that the relative order inside both the even and odd groups should remain as it was in the input.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.


#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to rearrange linked list.
ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* secondhead = head->next;
    ListNode* temp = secondhead->next;
    ListNode* curr1 = head;
    ListNode* curr2 = secondhead;
    bool odd = true;
    while (temp != nullptr) {
        if (odd) {
            curr1->next = temp;
            curr1 = temp;
            odd = false;
        } else {
            curr2->next = temp;
            curr2 = temp;
            odd = true;
        }
        temp = temp->next;
    }
    curr1->next = secondhead;
    curr2->next = nullptr;
    return head;
}

// Function to print the linked list.
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Main function to test the oddEvenList function.
int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    // Rearranging the linked list.
    head = oddEvenList(head);

    std::cout << "Modified list: ";
    printList(head);

    // Free allocated memory (for good practice).
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
