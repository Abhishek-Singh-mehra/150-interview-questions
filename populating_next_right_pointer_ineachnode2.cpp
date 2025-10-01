/*Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.*/ 
 
/*  *********************** approach1 *******************************/
/* the intution is simple we use the bfs and  we use rev and curr pointer  prev ->next 
point to the curr and curr will be the que.front() node  lastly when we are finsihed 
 in a level we will point to he nullptr .*/ 
  
 /* time complexity  O(n)
   space complexity O(1)
    leetcode link =  https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/?envType=study-plan-v2&envId=top-interview-150 */ 

    /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if ( !root)
            return nullptr;
      
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
           int size = que.size(); 
            Node * prev = nullptr ;
             for(int i=0 ; i<size ; i++)
             {
                 Node * curr = que.front();
                  que.pop();
                   if(prev) prev ->next = curr ;
                   prev = curr ;
                   if(curr->left) que.push(curr->left);
                   if(curr ->right) que.push(curr ->right);
             } 
             prev ->next= nullptr ;
        }  
         
         return root ;
    }
};