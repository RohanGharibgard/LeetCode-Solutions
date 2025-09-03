
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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *lead = head->next;
        ListNode *pivot = head;

        // Go through the list
        while (/*pivot != nullptr && */ lead != nullptr)
        {
            // if the value at lead is equal to the value of pivot
            if (lead->val == pivot->val)
            {
                // emit the node from the list
                pivot->next = lead->next;
                // move the lead to the next node
                lead = lead->next;
            }
            else
            {
                // iterate both pivot and lead
                pivot = lead;
                lead = lead->next;
            }
        }

        return head;
    }
};
