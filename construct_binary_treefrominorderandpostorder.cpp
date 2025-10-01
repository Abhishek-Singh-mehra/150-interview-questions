/* Given two integer arrays inorder and postorder
 where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree,
  construct and return the binary tree.

 */
 
  /**************** approach 1 ***************************** */
   /* the intution is simple that we will travel in the postorder vector from lasr 
   as it indiciates the root then we will search it in the inorder vector and 
    divide it as the  after idx are to  be on the right side and before that it should be 
     on the left node .*/

     /* time complexity O(n)
       space compleixty O(1).
        leetcode link = https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150 */
         
        /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildingtree(vector<int>& inorder, vector<int>& postorder,
                           int start, int end, int& idx) {
        if (start > end)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[idx--]);
        int i = start;
        while (i <= end) {
            if (inorder[i] == root->val)
                break;
            i++;
        }

        root->right = buildingtree(inorder, postorder, i + 1, end, idx);
        root->left = buildingtree(inorder, postorder, start, i - 1, idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // we will iterate in the postorder in reverse manner.
        int n = postorder.size()-1;
        return buildingtree(inorder, postorder, 0, inorder.size() - 1, n);
    }
};