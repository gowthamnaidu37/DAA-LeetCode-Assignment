#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify handling edge cases
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        // Merge the lists while both have remaining elements
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Attach the remaining elements from either list
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        // Save the head of the merged list
        ListNode* mergedHead = dummy->next;
        delete dummy; // Free the dummy node
        return mergedHead;
    }
};
