// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, 
// where ⌊x⌋ denotes the largest integer less than or equal to x.
// For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.


#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to delete the middle node
ListNode* deleteMiddle(ListNode* head) {
    if(head->next == nullptr) return nullptr;
    ListNode* slow = head;
    ListNode* temp = nullptr;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = slow->next;
    delete slow;
    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while(current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Helper function to create a linked list from an array of values
ListNode* createList(const vector<int>& values) {
    if(values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for(size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Create a list from an array of values
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);

    // Print the original list
    cout << "Original list: ";
    printList(head);

    // Delete the middle node
    head = deleteMiddle(head);

    // Print the modified list
    cout << "Modified list: ";
    printList(head);

    // Free allocated memory
    while(head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
