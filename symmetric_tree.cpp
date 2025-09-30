/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).*/ 
 
/****************approach1 ********************* */
 /* the intution  is simple we will check  for the left and right child
  to be equa land call  recurssive function to check its children too 
   as left ->left and right ->right eual and left ->right  and right ->left equal.*/ 

 
   /* time compleixty O(h)
   space compleixty O(1)
    leetcode link =  https://leetcode.com/problems/symmetric-tree/?envType=study-plan-v2&envId=top-interview-150 */
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
 bool mirror( TreeNode * left , TreeNode * right)
 {
    if(!left && !right) return true ; 
     if( !right || !left ) return true ;
      return (left->val == right ->val) && mirror(left ->left , right ->right) && mirror(left ->right , right ->left);
 }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true ;
         return mirror(root ->left , root ->right);
    }
};