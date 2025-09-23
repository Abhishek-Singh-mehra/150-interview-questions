/*You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/
  
/* ****************************approach 1 ******************************/
/* the intution  is that we first convert the link list to the number and then add them and then convert it 
  to the link list .*/
  /* time compleixty O(n+m).
   space  compleixty O(n+m).*/
 
 /* 
**
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long num1 = listToNumber(l1);
        long long num2 = listToNumber(l2);
        long long sum = num1 + num2;
        return numberToList(sum);
    }

private:
    long long listToNumber(ListNode* head) {
        long long num = 0, multiplier = 1;
        while (head) {
            num += head->val * multiplier;
            multiplier *= 10;
            head = head->next;
        }
        return num;
    }

    ListNode* numberToList(long long num) {
        if (num == 0) return new ListNode(0);
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        while (num > 0) {
            current->next = new ListNode(num % 10);
            num /= 10;
            current = current->next;
        }
        return dummy->next;
    }
}; 




/********************************approach 2 ************************************ */
 
/* the intution is that  we use the   the pointer approach and the  carry variable whe never we add two number  and the carry is generated we 
 will add tho the number other wise we add 0 to the  numbe and move forward 
  condition  is that we will add the number till the number are equa lof size  of linklist . */
   /* time compleixty O(n+m)
    space compleixty O(n+m)
     leetcode link = https://leetcode.com/problems/add-two-numbers/?envType=study-plan-v2&envId=top-interview-150*/ 

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * temp1 = l1 ;
        ListNode * temp2 = l2;
         ListNode * l3=  new ListNode(0);
          ListNode * head = l3;
          int carry =0; // carry variable .
           
          while(temp1 && temp2)
          {
              
               int val = temp1->val + temp2 ->val + carry ;
               carry = val /10;
               l3 ->next = new ListNode(val%10);
                temp1 = temp1->next ;
                 temp2  = temp2 ->next;
                  l3 = l3->next ;
          }
            while(temp1)
            {
                 int val = temp1->val  + carry ;
               carry = val /10;
               l3 ->next = new ListNode(val%10);
                temp1 = temp1->next ;
                  l3 = l3->next ; 
            }


            while(temp2)
            {
                 int val = temp2->val  + carry ;
               carry = val /10;
               l3 ->next = new ListNode(val%10);
                temp2 = temp2->next ;
                  l3 = l3->next ; 
            }
          
           if(carry)
           {
             l3 ->next = new ListNode(carry);
           }
        return head ->next ;
    }

};

     
