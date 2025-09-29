/*Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 */
 
  /********************************** approach 1 *************************************** */ 
   /*the intution is that we will recurssive traversal to the both tree if we  at any stage get the value not equal we will return false 
     */ 
     /*time complexity O(h)
      space complexity O(1).
       leetcode link = https://leetcode.com/problems/same-tree/description/?envType=study-plan-v2&envId=top-interview-150 */ 
       /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
         if(!p && !q) return true ;
          if(!p || !q) return false ;
           if( p->val != q->val) return false ;
           return  isSameTree(p->left , q->left ) && isSameTree(p->right , q->right); 

    }
};