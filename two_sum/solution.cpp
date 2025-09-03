/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    unsigned long listToInt(ListNode* list) {
        unsigned long num = 0;
        unsigned long base = 1;
        while (list != nullptr) {
            num += list->val * base;
            list = list->next;
            base *= 10;
        }
        return num;
    }

    ListNode* intToList(unsigned long num) {
        ListNode* start = new ListNode(num % 10);
        num /= 10;
        ListNode* iter = start;
        while (num != 0) {
            iter->next = new ListNode(num % 10);
            iter = iter->next;
            num /= 10;
        }

        return start;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned long num1 = listToInt(l1);
        unsigned long num2 = listToInt(l2);

        return intToList(num1 + num2);
    }
};
