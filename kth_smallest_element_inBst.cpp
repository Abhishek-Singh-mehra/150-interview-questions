/*Given the root of a binary search tree, and an integer k, 
return the kth smallest value (1-indexed) of all the values of the nodes in the tree.*/
 
/***********************approach 1 *************************** */
/* the intution is that we should traversel the bst by inorder ans store it in the vector ,then
return the k-1 element ,as the inorder is in sorted fashion.*/
 /*time complexity O(n)
    space complexity O(h)
     leetcode link = https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-interview-150*/
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
   void inorder(TreeNode * node  , vector<int>&ans)
   {
      if(!node ) return ; 
      if(node ->left) inorder(node ->left , ans);
      ans.push_back(node ->val);
      if(node ->right) inorder(node ->right , ans);
      
   }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root , ans);
         return ans[k-1];
    }
};