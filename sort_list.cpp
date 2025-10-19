/*Given the head of a linked list, return the list after sorting it in ascending order.*/ 
 /* ************************** approach 1 ******************************/
 /* the first intution is that we first extract the element from  list the nsort it and then  make a list .*/
  /* time complexity O(n+nlog(n))
   space compleixty O(n)*/ 
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
    ListNode* sortList(ListNode* head) {
        vector<int> duplicate;
        if (head == NULL)
            return NULL;
        ListNode* temp = head;
        while (temp != NULL) {
            duplicate.push_back(temp->val);
            temp = temp->next;
        }
        sort(duplicate.begin(), duplicate.end());
        ListNode* newhead = new ListNode(duplicate[0] );
  ListNode * current = newhead;
        for (int i = 1; i < duplicate.size(); i++) {
                current ->next = new ListNode(duplicate[i]);
                current  = current ->next ; 
        }
        return newhead;
    }
}; 




/*************************************** approach 2 ********************************* */
 /* the inttuion is using the  merge sorting algorithm it works like this 
   1 . get the middle by using the slow an fast pointer.
    2 . then recursive call for the left part and  the right part to divide it more .
    3 .merge the part seprately . */
     /* time compleixty O(nlog(n))
        space compleizty O(1).
         leetcode link = https://leetcode.com/problems/sort-list/description/?envType=study-plan-v2&envId=top-interview-150*/ 
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
   ListNode *  merge( ListNode * left ,ListNode * right)
   {
      ListNode * ptr = new ListNode(0);
      ListNode * curr =ptr;
       while( left !=NULL && right !=NULL)
       {
         if(left ->val <= right ->val)
         {
             curr ->next = left ;
             left  =left ->next ;
         } 
         else
         {
             curr ->next = right;
             right = right ->next ;
         } 
         curr = curr ->next ;
       } 
         if(left !=NULL)
         {
             curr ->next = left ;
              left = left ->next ;
         } 
         if(right !=NULL)
         {
             curr ->next = right ;
              right= right ->next ;
         } 
        return ptr ->next ;
   }
    ListNode* sortList(ListNode* head) {
         if(head ==NULL || head ->next ==NULL) return head ;
          ListNode * temp =head ;
          ListNode * slow =  head ;
          ListNode * fast = head ;
           while(fast !=NULL && fast ->next !=NULL)
           {
               temp = slow ;
               slow = slow ->next ;
               fast = fast ->next ->next ;
           }  
           temp ->next =NULL; // important . to get seprate / stop the list.
           ListNode *left = sortList(head);
           ListNode *right = sortList(slow); 
           return  merge(left ,right);    
    }
};