/*Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
 */
/********************************** the approach 1 ***************************** */ 
/* the intution is simple as we know that in binary tree left side is smaller number and right side is greater number 
  dividing the  sorted array into the two then building the binary tree.*/
  /* time compleixty O(n/2)
     space compleixty O(n/2) 
     leetcode link = https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/?envType=study-plan-v2&envId=top-interview-150*/
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
         return maketree(nums ,  0 ,nums.size()-1);
    }
    TreeNode* maketree( vector<int>&nums ,  int left  , int right)
    {
         if(left>right) return nullptr;
          int mid =  left + (right - left)/2;
          TreeNode * root = new TreeNode(nums[mid]);
         root  ->left = maketree(nums ,  left  ,mid-1);
         root  ->right = maketree(nums ,  mid +1 ,right);
          return root ;
    }
     
};