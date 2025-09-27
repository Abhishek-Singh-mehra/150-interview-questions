/*Given the head of a linked list, rotate the list to the right by k places.
 */
/************************approach 1****************************** */
/* the intution of this is same  of  rotating the array by k as we first reverse the list then ,
 reverse the araay from left +k node to the end .*/
/* time complexity O(n).
 space complexity O(1)
  leetcode link = https://leetcode.com/problems/rotate-list/description/?envType=study-plan-v2&envId=top-interview-150 */
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
    void reversell(ListNode **head)
    {
        if (head == nullptr)
            return;
        ListNode *curr = *head;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        *head = prev;
        return;
    }

    void reversella(ListNode **head, int k)
    {

        ListNode *t2 = *head;
        ListNode *dummy = NULL;
        int count = k;
        while (count - 1 != 0 && t2 != NULL)
        {
            t2 = t2->next;
            count--;
        }
        if (t2 == NULL)
            return;
        dummy = t2->next;
        t2->next = NULL;
        reversell(head);
        t2 = *head;
        while (t2->next != NULL)
        {
            t2 = t2->next;
        }

        reversell(&dummy);
        t2->next = dummy;
        return;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (k == 0 || head == nullptr || head->next == nullptr)
            return head;
        int count = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        count = k % count;
        if (count == 0)
            return head;
        // now reverse the whole linklist .
        reversell(&head);
        reversella(&head, count);
        return head;
    }
};