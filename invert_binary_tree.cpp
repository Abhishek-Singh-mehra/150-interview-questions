/*Given the root of a binary tree, invert the tree, and return its root.*/ 
 /******************approach 1 * ************************** */
  /* the intution is that  we  just swap the root left with the right and then call the recurrsive to get all them change .*/
   /* time complexity O(h).
    space complexity O(1).
     leetcode link = https://leetcode.com/problems/invert-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150 */ 
      
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr; //base case.
         TreeNode * temp = root->left ;
          root ->left = root ->right;//swaping techn.
           root ->right = temp;
         invertTree(root->left ); // function call.
         invertTree(root->right );  
         return root ;
    }
};