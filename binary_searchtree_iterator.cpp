/*
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor.
 The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.


 */
 
  /***************************** approach 1 ************************** */
  /*the intution is that we use stack to store the left  side of the node   that is given 
   to us as thsi help to get the smallest number and the bool is thier is still small number 
   as   the node we hav eget if it have the left then also to push to the stack.*/ 
    /* tim complexity O(1).
     space complexity O(h).
      leetcode link = https://leetcode.com/problems/binary-search-tree-iterator/?envType=study-plan-v2&envId=top-interview-150 */

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
class BSTIterator {
    private :
         stack<TreeNode * >st;
         void pushlefts(TreeNode * node )
         {
             while(node)
             {
                st.push(node);
                node = node ->left;
             }
         }
public:
    BSTIterator(TreeNode* root) {
        pushlefts(root);
    }
    
    int next() { 
         TreeNode * node = st.top();
         st.pop();
         if(node ->right)
         {
             pushlefts(node ->right);
         }
          return node ->val;
        
    }
    
    bool hasNext() {
         if(!st.empty()) return true ;
         return false ;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */