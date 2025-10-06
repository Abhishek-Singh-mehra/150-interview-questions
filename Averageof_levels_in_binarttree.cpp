/*Given the root of a binary tree, return the average value of the nodes on each level in the form of an array.
 Answers within 10-5 of the actual answer will be accepted.
 */

 /******************** approach 1 *************************** */
 /* the approach is simple we sue the bfs to traverse eac hlevle of node and on each ever level we will geet the sum
 then reset the sum and pus hit to the ans vector by getting its average be dividing by its size .*/
 /* time complexity O(n)
    space complexity O(h)
    leetcdoe link= https://leetcode.com/problems/average-of-levels-in-binary-tree/?envType=study-plan-v2&envId=top-interview-150 */ 
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
    void bfs(TreeNode* root, vector<double>& ans) {
        if (!root)
            return;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int n = que.size();
            long long  sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* node = que.front();
                sum += node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
                que.pop();
            }
            ans.push_back((double)sum / n);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        bfs(root, ans);
        return ans;
    }
};
