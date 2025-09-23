/*Given head, the head of a linked list,
 determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
 Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.*/
 
 /**********************approach 1 ****************************************** */ 
 /* the intution is that we use use the two pointer approach slow and fast slow is moving at normal speed 
  and fast move will at 2x speed so if they point at same in fututre means that the fast is behind the slow that only 
  when their is cycle so return true , other false .*/
   /* time complexity O(n)
   space compleixty O(1).
    leetcode link = https://leetcode.com/problems/linked-list-cycle/?envType=study-plan-v2&envId=top-interview-150*/ 

    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
         if(head == NULL || head ->next ==NULL)
         {
             return false ;
         }
          ListNode * slow = head ;
           ListNode * fast = head ;
            while(fast!=NULL && fast->next!=NULL)
            {
                  slow = slow ->next ;
                  fast  = fast ->next ->next ;
                   if(slow == fast)
                   {
                     return true;
                   }
            }
             return false;
    }
};