/*Given two integer arrays preorder and inorder 
where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree,
 construct and return the binary tree.*/ 
  
 /*****************approach 1 ***************** */
  /* if we look closely in the preorder and inorder pattern the preorder we will get the root and 
   search  the value in the inorder to find its children as its left will be a head of him inorder and behind the inoder
     same as we will do will the other as recuresively .
      eample 1 preorder: 3   9    20    15    7 
                         idx
               inorder: 9    3     15     20   7 
                        start                 end
                 so the first will be the 
                      3
                    /   \
                  9     15 20 7  like this */ 

/* time complexity O(n)
   space complexity O(n) 
   leetcode link  =https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150 */ 

  
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
   TreeNode* solve(vector<int>& preorder, vector<int>& inorder  , int& idx , int start  , int end)
   {
     if(start>end) return NULL;
      
      int  rootval =  preorder[idx]; 
      int i = start;
       for(  ; i <= end  ;i++)
       {
         if( rootval == inorder[i])break;
       }
         idx++;

         TreeNode * root = new TreeNode(rootval);
         root->left  = solve(preorder , inorder , idx , start , i-1);
         root->right  = solve(preorder , inorder , idx , i+1 , end); 
          return root;

   }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int idx = 0; //preorder traversal.
           return  solve(preorder , inorder , idx , 0 , preorder.size()-1);
    }
};