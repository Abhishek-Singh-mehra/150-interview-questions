/*Given the root of a binary tree, return the level order traversal of its nodes' values.
 (i.e., from left to right, level by level).

 */

 /************************************ approach 1 ***************************** */ 
  /* the intution si that we sue the bfs  to traversel the levels &
  ,each level is collected in the vector and after levle traversal we will
   push it to the ans vector.*/
   /*time complexity O(n)
     space complexity O(h).
     leetcdoe link = https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150 */ 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>>result;  
          if(root==NULL)  return result ;
          queue<TreeNode*>q;
           q.push(root);
            while(!q.empty())
            {
                  int size = q.size();
                   vector<int>ans;
                    for(int i=0 ;i<size;i++)
                    {   
                            TreeNode* num = q.front();
                            q.pop();
                            ans.push_back(num->val); 
                             if(num->left) q.push(num->left);
                             if(num->right)q.push(num->right);
                            
                         
                    }  
                     result .push_back(ans);
            }
             return result ;
          
    }
};