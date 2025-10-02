/*Given the root of a binary tree and an integer targetSum,
 return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children*/

/****************** approach1 ********************************* */
/* the intution is simple we will use the dfs methord to get all the sum at each level
whaen we look that sum is equa lt ot the  targetsum and thenir is not left and right dhild left then only we return true,
other wise false ;*/
/* time compelxity O(h) hegiht o tree.
   space compleixty O(1)
   leetcode link = https://leetcode.com/problems/path-sum/description/?envType=study-plan-v2&envId=top-interview-150 */

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
class Solution
{
public:
    bool dfs(TreeNode *root, int targetsum, int sum)
    {
        if (root == nullptr)
            return false;
        sum += root->val;
        if (sum == targetsum && root->left == nullptr && root->right == nullptr)
            return true;
        return dfs(root->left, targetsum, sum) || dfs(root->right, targetsum, sum);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return dfs(root, targetSum, 0);
    }
};
