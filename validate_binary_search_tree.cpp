/*Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/ 
 
/*****************************approach 1 ********************** */ 
 /* the intution is that we use the resurrsion approach which return the truee if the node below are 
 in the  valid bst format if not return the false, base condition is  that if we reac hthe lef node return the true . */ 
  /* time complexity O(n)
  space complexity O(1)
   leetcode link= https://leetcode.com/problems/validate-binary-search-tree/description/?envType=study-plan-v2&envId=top-interview-150*/ 
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
     bool  valid(TreeNode * root , long long minval , long long maxval )
     {
         if( root ==nullptr ) return true ; //base condition 
          if(root->val <=minval || root->val >=maxval ) return false; //comparing the values  to the node val.
          return valid(root->left , minval , root->val)&&
          valid(root->right  , root->val  , maxval );
     }
    bool isValidBST(TreeNode* root) {
        
         return  valid(root , LLONG_MIN,  LLONG_MAX);
    }
};