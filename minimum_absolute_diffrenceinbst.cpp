/*Given the root of a Binary Search Tree (BST),
 return the minimum absolute difference between the values of any two different nodes in the tree.
 */ 
/* ************************************ approach 1************************************/
/* the intution is that we know about the bst have the smaller number to the left and bigger to  its right
and in order traversal have left root  then right which means if we travere the inorder traveral then we can get the smallest 
 diffrence between node as we ahve the prev pointer that point to  the prev node rom which we are subtracting and get the diffrence .*/ 
  /* time complexity O(n)
  space complexity O(1).
   leetcdoe link = https://leetcode.com/problems/minimum-absolute-difference-in-bst/?envType=study-plan-v2&envId=top-interview-150 */ 
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
   void inorder(TreeNode * node , TreeNode * &prev   , int &diff)
   {
    if(!node) return ;
     inorder(node ->left , prev , diff); //left move .
      if(prev) // chacking to the main for the diffrence .
      {
         diff = min(diff , abs(node ->val  -prev->val));
      } 
      prev =node ;
      inorder(node ->right , prev , diff); //right move.
   }
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        TreeNode * prev = nullptr;
        inorder(root , prev , diff);
         return diff;
    }

};