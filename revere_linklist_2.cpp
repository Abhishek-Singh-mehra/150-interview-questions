/*Given the head of a singly linked list and two integers left and right where left <= right,
 reverse the nodes of the list from position left to position right, and return the reversed list.*/
  
  /*****************approach 1 ************************** */
   /* the intution si that we first  traverse to the left count pointer and then we will se the oreder for the first two nodes and try to 
    correct them  then move forward iterate  till left - right  iterations .*/ 
     /* time complexity O(n).
      spcae complexity O(1).
       leetcdoe link =  https://leetcode.com/problems/reverse-linked-list-ii/?envType=study-plan-v2&envId=top-interview-150 */

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if( head == NULL || head ->next == NULL) return head ;
          ListNode* dummy = new ListNode(0);   //edge case if the left =1 then the head s ishange so we use the dummy node .
           dummy ->next = head ;
            ListNode *prev = dummy ;

           for(int i=1 ; i<left  ; i++) // traverse to the starting of the node to be reverse .
           {
              prev = prev ->next ;
           } 
           ListNode * curr = prev ->next ;

           for(int i=1 ; i<=(right -left) ; i++)
           {
               ListNode * temp = prev ->next ;
               prev ->next = curr->next ;
                curr ->next  = curr->next ->next ;
                prev ->next ->next = temp;
           } 
           return dummy ->next ;
    }
};