/*Given the head of a linked list,
remove the nth node from the end of the list and return its head.*/

/********************approach 1 ******************* */
/* simple approac h first get the count ofthe  number of nodes then  travesel the
 node till the count -n theen node ->next = node ->next ->next  , take  care of the
 edge case for that we want the dummy node .*/
/* time complexity O(n).
 spcae complexity O(1).
  leetcode link  =https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=study-plan-v2&envId=top-interview-150 */

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0, head); // dummy node to handle edge cases
        ListNode *temp = &dummy;

        int count = 0;
        ListNode *curr = head;
        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }

        for (int i = 0; i < count - n; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        return dummy.next;
    }
};
