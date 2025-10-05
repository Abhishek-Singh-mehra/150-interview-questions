/*Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.
*/
 
 /******************************approach 1 *********************************** */
 /* the intution is that using the bfs then when we are traversing the every layer we will sor the lst element of the level and 
 push to ans ,by maaking an another variable .*/
 /* time complexity O(n)
  space comlexity O(h)
   leetcode link =  https://leetcode.com/problems/binary-tree-right-side-view/?envType=study-plan-v2&envId=top-interview-150 */ 
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
 void bfs( TreeNode * root  , vector<int>&ans)
 {
    queue<TreeNode * >que;
    que.push(root);
    TreeNode * rightmost = NULL;
    while(!que.empty())
    {
         int size = que.size();
          for(int i=0; i<size ; i++)
          {
             rightmost = que.front();
             if(que.front()->left) que.push(que.front()->left);
             if(que.front()->right)que.push(que.front()->right);
              que.pop();
          }
          if(rightmost) ans.push_back(rightmost->val);
    }
 }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
         if(!root) return ans;
         bfs(root ,ans);
          return ans ;
    }
};