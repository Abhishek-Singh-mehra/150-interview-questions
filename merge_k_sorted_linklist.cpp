/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 */  
/********************************** approach 1 ************************** */
 /* the intution i that we use the merge sorting technique as we will consider the whole  vector as an  the single link list 
     and rest is the merge sort .*/
      /* time compleixty O(nlog(n))
       space complexity O(n)
        leetcode link = https://leetcode.com/problems/merge-k-sorted-lists/?envType=study-plan-v2&envId=top-interview-150*/ 

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
    ListNode* mergenode(ListNode* head1, ListNode* head2) {
        
        if (head1==NULL) return head2;
        if(head2 == NULL )return head1;
          ListNode* head = NULL;
        ListNode* tail = NULL;
         ListNode* temp1 = head1; 
         ListNode* temp2 = head2;
        if (head1->val >= head2->val) {
            head = head2;
            tail = head; 
            temp2 = temp2->next ;
        }
         else {
            head = head1;
            tail = head; 
            temp1 = temp1->next ;
        } 
          while(temp1!=NULL && temp2!=NULL)
          {
                if( temp1->val>=temp2->val)
                {
                   tail->next = temp2;
                     tail = temp2 ;
                      temp2 = temp2->next ;
                    
                } 
                  else
                  {
                     tail ->next = temp1;
                      tail = temp1 ;
                       temp1 = temp1->next;
                  }
          } 
           if(temp1!=NULL)
           {
             tail ->next = temp1;

           } 
           else
           {
             tail ->next = temp2;
           }

        return head;
    } 
     ListNode * partitionmerge(int start  , int end ,  vector<ListNode*> &lists)
     {
         if( start>end) return NULL;
         if( start == end )
         {
             return lists[start];
         }  
          int mid = start +(end - start)/2;
          ListNode*  l1 = partitionmerge(start , mid ,lists);
          ListNode* l2 = partitionmerge(mid+1 , end ,lists); 
           return   mergenode(l1 , l2);
     }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         
           int k = lists.size();
            if( k==0) return NULL;
            return partitionmerge(0 , k-1 , lists);
    }
};