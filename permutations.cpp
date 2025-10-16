/*Given an array nums of distinct integers, return all the possible permutations.
 You can return the answer in any order.*/

 /* ***************************** approach 1 ****************************************/
 /* the appraoc  is simple we will use the backtracking we will use the recurssion approach t ogat a number the nlastly pop it back mans
  undo the last element */
  /* time compleixty O(n.n!)
    space complexity O(n).
    leetcode link = https://leetcode.com/problems/permutations/?envType=study-plan-v2&envId=top-interview-150 */

    class Solution {
public: 
 void backtrack(vector<int>nums , int indx    , vector<vector<int>>& ans)
 {
     if(indx == nums.size())
     {
          ans.push_back(nums);
           return ;
     }  
      for(int i= indx ; i<nums.size() ; i++)
      {
         swap(nums[i] , nums[indx]);
         backtrack(nums , indx+1  ,ans);
         swap(nums[i] ,nums[indx]);
      }
     
 }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>ans;
   
        backtrack(nums , 0 ,ans);
        return ans;
    }
};