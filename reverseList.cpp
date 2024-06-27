// Given the head of a singly linked list, reverse the list, and return the reversed list.

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* prev = head;
    ListNode* curr = head->next;
    ListNode* temp = curr->next;
    prev->next = nullptr;
    while (temp) {
        curr->next = prev;
        prev = curr;
        curr = temp;
        temp = temp->next;
    }
    curr->next = prev;
    prev = curr;
    return curr;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Helper function to create a new node
ListNode* createNode(int value) {
    return new ListNode(value);
}

int main() {
    // Create a linked list 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    std::cout << "Original list: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    std::cout << "Reversed list: ";
    printList(head);

    return 0;
}
