/*Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.*/
 
/*  ************************* approach 1 ************************/ 
 /* the intution is that we first chek if the linklist have enoughnodes to reverse  if yes the nwe will get to he starti gno f the node the n
  we will call  the function  to reverse the linklist of particular group special take care of the edge caase andhow we link and move forward .*/ 
   /* time complexity O(n).
    space complexity O(1)
     leetcode link = https://leetcode.com/problems/reverse-nodes-in-k-group/description/?envType=study-plan-v2&envId=top-interview-150
      youtube video  = https://www.youtube.com/watch?v=-swgIiMIlJo */  

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
    void reversell(ListNode** head) {
        ListNode* temp = *head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (temp != NULL) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        *head = prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
    
         ListNode* temp1 = head;
        ListNode* temp2 = head; 
        ListNode* HEAD = NULL;
        ListNode* tail = NULL;
        ListNode* dummy = NULL;

        while (temp1 != NULL) {
            // Check if there are enough nodes to reverse
            int count = k - 1;
            temp2 = temp1;
            while (count != 0 && temp2 != NULL) {
                temp2 = temp2->next;
                count--;
            }
            // If temp2 is NULL, there are fewer than k nodes left, so we exit
            if (temp2 == NULL) {
                break;
            }

            // Proceed with reversing the k-group
            dummy = temp2->next;
            temp2->next = NULL;
            reversell(&temp1); // Reverse the segment starting from temp1

            // Update HEAD if this is the first reversed group
            if (HEAD == NULL) {
                HEAD = temp1;
            }
            
            // Link the previous group's tail to the current group's head
            if (tail != NULL) {
                tail->next = temp1;
            }

            // Move tail to the end of the reversed group (original head)
            tail = head;

            // Reattach the reversed group to the rest of the list
            head->next = dummy;

            // Update pointers for the next group
            temp1 = dummy;
            head = temp1;
        }

        return HEAD ? HEAD : head;
    }
};