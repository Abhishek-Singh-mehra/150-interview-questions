/*You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

 */
/* ******************************** approach 1 ****************************/
/* the approac his to use the dfs  and add the root ->val to the sum variable at last of the leaf node we will
add this to the ans variable , lastly return  the and variable.*/
/* time complexity O(n)
 space complexity O(h)
    leetcode link  = https://leetcode.com/problems/sum-root-to-leaf-numbers/description/?envType=study-plan-v2&envId=top-interview-150 */
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
    int ans;
    void dfs(TreeNode *root, int sum)
    {
        if (!root->left && !root->right)
        {
            // base  case ;
            sum = sum * 10 + root->val;
            ans += sum;
            return;
        }
        if (root->left)
            dfs(root->left, sum * 10 + root->val);

        if (root->right)
            dfs(root->right, sum * 10 + root->val);
        return;
    }
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        ans = 0;
        dfs(root, sum);
        return ans;
    }
};