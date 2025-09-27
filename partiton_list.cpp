/*Given the head of a linked list and a value x, 
partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.*/
  
/****************************** approach 1 ******************************** */
 /* the intution is that we build two diffrent linklist one store theless element than x
  and other store the greater and equal to the x . then at last connect both of them.*/
   
  /* time complexity O(n)
   space complexity O(n)
    leetcode link = https://leetcode.com/problems/partition-list/?envType=study-plan-v2&envId=top-interview-150 */ 
     
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* curr = head;
        ListNode* lesshead = nullptr;
        ListNode* lesstail = nullptr;

        ListNode* greaterhead = nullptr;
        ListNode* greatertail = nullptr;

        while (curr != nullptr) {
            if (curr->val < x) {
                // it should be in less head .
                if (lesshead == nullptr) {
                    lesshead = new ListNode(curr->val);
                    lesstail = lesshead;

                } else {
                    ListNode* temp = new ListNode(curr->val);
                    lesstail->next = temp;
                    lesstail = temp;
                }
            } else {
                // greater section .
                if (greaterhead == nullptr) {
                    greaterhead = new ListNode(curr->val);
                    greatertail = greaterhead;

                } else {
                    ListNode* temp = new ListNode(curr->val);
                    greatertail->next = temp;
                    greatertail = temp;
                }
            }
            curr = curr->next;
        }
        // now to attach the less tail with the greater head .
        if(lesstail)
        {
              lesstail->next = greaterhead;
               return lesshead;
        }
         else{
                return greaterhead;
         }
       
    }
};
