/* You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.*/
 
/*******************approach 1 ********************************* */
 /* the intution is  that we  use a pointer header and tail at the tarting header should point 
  to the smaller value of temp1 or temp2 and tail opposite to it now we will itterate to the linklist 
   and compare both the node which ever node is smaller the tail is  will move to that adn point to the 
    node and  that node pointer will  move further only , lastlty if any linklist  reamins we will just add that to the tsail. */
     
    /* time compleixty O(n+m).
       space compleixty  O(1).
    leetcode link = https://leetcode.com/problems/merge-two-sorted-lists/?envType=study-plan-v2&envId=top-interview-150 */
    
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        ListNode* head = NULL;
        ListNode* temp1 = list1;
        ListNode* tail = NULL;
        ListNode* temp2 = list2;
        if (list1->val >= list2->val) {
            head = list2;
            tail = head;
            temp2 = temp2->next;
        }

        else {
            head = list1;
            tail = head;
            temp1 = temp1->next;
        }
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val >= temp2->val) {
                tail->next = temp2;
                tail = temp2;
                temp2 = temp2->next;
            } else {
                tail->next = temp1;
                tail = temp1;
                temp1 = temp1->next;
            }
        }
        if (temp1 != NULL) {
            tail->next = temp1;
        } else {
            tail->next = temp2;
        }
        return head;
    }
};