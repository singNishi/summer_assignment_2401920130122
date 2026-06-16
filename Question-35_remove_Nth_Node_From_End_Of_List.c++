#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = NULL;
    }

    ListNode(int x) {
        val = x;
        next = NULL;
    }

    ListNode(int x, ListNode* next) {
        val = x;
        this->next = next;
    }
};

ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* fast = head;
    ListNode* slow = head;

    // Move fast n steps ahead
    for(int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // If head is to be removed
    if(fast == NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Move both pointers
    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete nth node from end
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return head;
}

// Function to print linked list
void printList(ListNode* head) {

    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    // Create list: 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    head = removeNthFromEnd(head, n);

    printList(head);

    return 0;
}