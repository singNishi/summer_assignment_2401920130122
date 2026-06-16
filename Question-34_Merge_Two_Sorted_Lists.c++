#include <iostream>
using namespace std;

// Definition of singly linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;

    while (list1 != NULL && list2 != NULL) {

        if (list1->val <= list2->val) {
            temp->next = list1;
            list1 = list1->next;
        }
        else {
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    // Remaining nodes
    if (list1 != NULL) {
        temp->next = list1;
    }

    if (list2 != NULL) {
        temp->next = list2;
    }

    return dummy->next;
}

// Function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // list1 : 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // list2 : 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* ans = mergeTwoLists(list1, list2);

    printList(ans);

    return 0;
}