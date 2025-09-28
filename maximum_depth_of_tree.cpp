/*Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 */

  /* ************************* approach1 *************************/
   /* we can use the breath first search  concept  as wewill count when we traversel the each layer .*/
   /* time complexity O(h) height of tree.
    space complexity O(1).*/
     
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
    int maxDepth(TreeNode* root) {
        //using the bfs (breath first search ).
        if(root ==nullptr ) return 0;
          queue<TreeNode*>que; 
           int depth =0;
           que.push(root);
            while( !que.empty())
            {
                 int size = que.size();
                  for(int i=0 ; i<size ; i++)
                  {
                     TreeNode *node = que.front();
                      que.pop();
                       if(node ->left) que.push(node ->left);
                       if(node ->right) que.push(node ->right);
                  } 
                   depth++;
            } 
             return depth;
           
    }
};

 
 /* ******************************** approach 2 *************************/ 
  /* we can use the dfs depth first search as it is the recurssive approach */ 
  /* time compleixty O(h)
    space complexity O(1).*/ 
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
    int maxDepth(TreeNode* root) {
        if(root ==nullptr) return 0;
         return 1 +max( maxDepth(root ->left ) , maxDepth(root ->right));
    }
}; 
     