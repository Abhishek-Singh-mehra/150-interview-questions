/*A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.*/

/********************************* approach 1 ************************ */
/* the intution is that think it in this way if i  am standing at the node if i can get the maximum sum from the left and
 right the nwe can get the sum of left + right + root ->val and then compare it with the sum max.*/
/* time complexity O(n)
   space  compleixty O(h)
    leetcdoe link = https://leetcode.com/problems/binary-tree-maximum-path-sum/?envType=study-plan-v2&envId=top-interview-150 */

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
    int call(TreeNode *root, int &sum)
    {
        if (!root)
            return 0;
        int left = max(0, call(root->left, sum));
        int right = max(0, call(root->right, sum));
        sum = max(sum, (left + right + root->val));
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode *root)
    {
        int sum = INT_MIN;
        call(root, sum);
        return sum;
    }
};