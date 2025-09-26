/*Given the head of a sorted linked list,
 delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
  Return the linked list sorted as well.
 */

 /*****************************approach1 *************************** */ 
  /* the approach is simple that we store the value with the frequency into ta ordered_map 
  adn lastly extract only those whose value is  equal to the 1 only and form the linklist .*/
   /* time complexity O(N).
    space complexity O(N)
    leetcode link  =https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/?envType=study-plan-v2&envId=top-interview-150 */

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
    ListNode* deleteDuplicates(ListNode* head){ 
         if( head ==nullptr)
         {
             return nullptr;
         }
           map<int ,int>countmap;
         ListNode * temp = head ;
          while( temp !=NULL)
          {
             countmap[temp->val]++;
             temp = temp->next ;
          } 
          ListNode * head2 = nullptr;
          ListNode * tail = nullptr ;
           temp =head;
          while(temp !=nullptr)
          { 
            if( countmap[temp->val]==1)
            {
                 ListNode* newnode = new ListNode(temp->val);
                 if(head2==nullptr)
                 {
                     head2 = newnode ;
                     tail = newnode ;
                 }
                  else 
                  {
                    tail ->next = newnode;
                    tail = tail ->next ;  
                  } 
            }
             temp  = temp->next ;
          }
          return head2;
    }
};