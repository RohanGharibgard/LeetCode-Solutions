#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    void printList(ListNode* start) {
        while (start != nullptr) {
            std::cout << start->val << ", ";
            start = start->next;
        }

    }
    // merge two sorted linked lists
    ListNode* mergeSortedLists (ListNode* list1, ListNode* list2) {
        // printList(list1);
        // std::cout << std::endl;
        // printList(list2);
        // std::cout << std::endl;

        if (list1 == nullptr) {
            return list2;
        }
        else if (list2 == nullptr) {
            return list1;
        }
        ListNode start;
        ListNode* tail = &start;

        
        while (list1 != nullptr && list2 != nullptr) {
            // get sublist of list2 where all elements are smaller than list1->val
            if (list2->val < list1->val) {

                tail->next = list2;
                list2 = list2->next;
            } else {
                tail->next = list1;
                list1 = list1->next;
            }
            tail = tail->next;
        }

        if (list1 != nullptr) {
            tail->next = list1;
        }
        else {
            tail->next = list2;
        }
    
        // std::cout << "Start value: " << start->val << std::endl;

        // std::cout << "Merged: ";
        // printList(start);
        // std::cout << std::endl;
        return start.next;
    }

    // Get the middle node of the linked list.
    ListNode* getMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        } 

        ListNode* temp = head;
        head = head->next;
        while (head != nullptr && head->next != nullptr) {
            temp = temp->next;
            head = head->next->next;
        }

        return temp;
    }


    // sort from [head, tail)
    ListNode* sortListHelper(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
    
        ListNode* mid = getMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        // std::cout << "Left half: ";
        // printList(head);
        // std::cout << "\nRight half: ";
        // printList(right);
        // std::cout << std::endl;
        
        ListNode* sortedList1 = sortListHelper(head);
        ListNode* sortedList2 = sortListHelper(right);

        // assume [head, mid) and [mid, tail) is sorted
        return mergeSortedLists(sortedList1, sortedList2);
    }

    ListNode* sortList(ListNode* head) {
        // Apply the merge-sort algorithm to a linked-list
        auto sortedList = sortListHelper(head);
        return sortedList;
    }
};
