class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *list; // list used to merge the two input lists
        ListNode *head; // head used to iterate through list

        // checking if either list contains values, to initialie the list
        if (list1 != nullptr || list2 != nullptr)
        {
            list = new ListNode();
            head = list;
        }

        // if list1 is empty, list 2 contains the sorted values
        // if list2 is empty, list 1 contains the sorted values

        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        // runs until we reach the end of either list
        while (list1 != nullptr && list2 != nullptr)
        {
            // obtain the least, current number from each list.
            int num1 = list1->val;
            int num2 = list2->val;

            // assign the largest value to our list
            if (num1 < num2)
            {
                head->val = num1;
                list1 = list1->next; // go to the next node
            }
            else
            {
                head->val = num2;
                list2 = list2->next; // go to the next node
            }

            // make sure that we are not at the end of the list
            // before creating another node.
            if (list1 != nullptr && list2 != nullptr)
            {
                head->next = new ListNode();
                head = head->next;
            }
        }

        // if there are remaining values in list1, append them now
        if (list1 != nullptr)
        {
            head->next = list1;
        }
        else if (list2 != nullptr)
        {
            // if there are remaining values in list2, append them now
            head->next = list2;
        }
        return list;
    }
};
