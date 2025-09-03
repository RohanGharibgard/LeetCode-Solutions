/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *newNode = nullptr;
        int sumOfDigits = l1->val + l2->val;
        ListNode *head = new ListNode(sumOfDigits % 10);
        ListNode *temp = head;

        while (l1->next != nullptr && l2->next != nullptr)
        {
            l1 = l1->next;
            l2 = l2->next;
            sumOfDigits = sumOfDigits / 10 + l1->val + l2->val;
            newNode = new ListNode(sumOfDigits % 10);
            temp->next = newNode;
            temp = newNode;
        }
        while (l1->next != nullptr)
        {
            l1 = l1->next;
            sumOfDigits = sumOfDigits / 10 + l1->val;
            newNode = new ListNode(sumOfDigits % 10);
            temp->next = newNode;
            temp = newNode;
        }

        while (l2->next != nullptr)
        {
            l2 = l2->next;
            sumOfDigits = sumOfDigits / 10 + l2->val;
            newNode = new ListNode(sumOfDigits % 10);
            temp->next = newNode;
            temp = newNode;
        }

        if (sumOfDigits > 9)
        {
            ListNode *newNode = new ListNode(sumOfDigits / 10);
            temp->next = newNode;
        }

        return head;
    }
};
