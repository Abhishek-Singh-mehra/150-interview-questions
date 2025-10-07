/*Given the root of a binary tree, 
return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 */
  
  /* ************************* approach 1 ****************************/
  /* the approach is simple we  use the breath first search to traverel into the level
   then we use the bool  flag  that is true and cahnge everytime we have the even or odd
   level as odd level we will reverse the ans and then push to the res vector.*/ 
   /*time complexity O(n)
   space complexity O(h)
    leetcdoe link =https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150 */ 
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
 void bfs(TreeNode * root , vector<vector<int>>&ans)
 {
   bool lefttoright =true;   //flag to reverse the odd level.
     queue<TreeNode *>que;
     que.push(root);
      while(!que.empty())
      {
           int n = que.size();
           vector<int>res(n);
           for(int i=0; i<n  ;i++)
           {
             TreeNode * node = que.front(); 
             que.pop();
             int index = lefttoright ?i:n-1-i;
             res[index]= node ->val;
             if(node ->left) que.push(node ->left);
             if(node ->right) que.push(node ->right);
            
            
           }
            ans.push_back(res);
             lefttoright = !lefttoright;
      }
 }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans ;
        if(!root) return ans;
         bfs(root , ans);
         return ans;
        
    }
};