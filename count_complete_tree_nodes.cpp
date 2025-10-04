/*Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last,
 is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible.
 It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity.*/

/**************************************approach 1 *********************** */
/*the intution is to use the dfs  we will add 1 + leftsum and the rightsum to ge the 
 count of the node to its leftside and rightside.*/
 /*time complexity O(n)
 space complexity O(n)
  leetcode link =https://leetcode.com/problems/count-complete-tree-nodes/?envType=study-plan-v2&envId=top-interview-150  */


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
   int  dfs(TreeNode * node)
  {
     if( !node) return 0;
      int leftsum =0, rightsum =0;
     if(node ->left)leftsum =dfs(node ->left);
      if(node ->right)  rightsum  =dfs(node ->right);
    
       return (1+leftsum +rightsum);
  }
    int countNodes(TreeNode* root) {
        return dfs(root );
    }
};