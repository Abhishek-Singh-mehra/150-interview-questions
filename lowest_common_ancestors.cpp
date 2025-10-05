/*Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants
 (where we allow a node to be a descendant of itself).”*/ 
  
  /****************************** approach 1 *************************** */
  /* the intution is thatt we will traverse the bianry tree as we are in root if root is nullthen no ancestors the nwhile traversing the bst 
  if we fount that root ==p || root ==q that means its the ancestor .*/ 
   
  /* time complexity O(n)
  space complexity O(h)
   leetcode link = https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/?envType=study-plan-v2&envId=top-interview-150*/

   /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { 
         if(root==NULL)
         {
             return NULL;
         }
          if(root ==p|| root ==q)
          {
             return root ;
          }
          TreeNode * leftn =  lowestCommonAncestor( root->left ,  p,  q);
           TreeNode * rightn =  lowestCommonAncestor( root->right ,  p,  q); 
            if(leftn!=NULL && rightn!=NULL)
            {
                 return root ;
            }
          if( leftn!=NULL)
          {
             return leftn;
          } 
           return rightn;
            
    }
};