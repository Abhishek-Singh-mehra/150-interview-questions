/*A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node.
 Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. 
 None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.*/

 
/******************************approach 1 ******************************** */
/* the intution is that we have to create the deep copy means exactly  same as the original one the proble mwe are facing 
 is that we want to set the random   before it get generated t osolve it we will  first make the original copy of that without using the random
   pointer the nto fix the random to that we have to  know about  where the original node i pointing so we will store the 
   node and its node where it pointing to the random and at last we will just fill it in the new copy of ours .*/
    /* time complexity O(n)
    space compleoxty O(n)  hash map.
    leetcode link = https://leetcode.com/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-interview-150 
    youtube  video link = https://www.youtube.com/watch?v=OLgXN2Yg3xQ&t=1702s */ 
     
    /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)return NULL;
        unordered_map<Node*, Node*>mp;
        Node* curr = head;
        Node* prev = NULL;
        Node* newhead = NULL;
        while (curr != NULL) {
            Node* temp = new Node(curr->val);
            mp[curr] = temp;
            if (newhead == nullptr) {
                newhead = temp;
                prev = newhead;
            } else {
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }
        curr = head;
        Node* newcurr = newhead;

        while(curr) {
            if (curr->random == NULL) {
                newcurr->random = NULL;
            } else {
                Node* randomoriginalnode = curr->random;
                Node* deepcopy = mp[randomoriginalnode];

                newcurr->random = deepcopy;
            }
            curr = curr->next ;
            newcurr = newcurr ->next ;
        }

        return newhead;
    }
};