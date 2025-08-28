/*You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.*/
 /* approach 1
   the intution  or the brute force approach will be 
    find all the possible  if any  possible approach i get he last indx i will return the true 
    otherwise false .
    */
  /* time complexity 0(n^k)  n is the size of the array and 
  k is the maximum num of every number at idx.
   space complexity 0(1).
  */

class Solution {
public:
    bool recc(vector<int>& nums, int i) {
        bool flag = false;
        if (i == nums.size()-1) {
            return true;
        }
        if (nums[i] == 0) {
            // no chance to move further.
            return false;
        } else {

            for (int j = 1; j <= nums[i]; j++) {
                flag = recc(nums, i + j);
                if (flag)
                    return true;
            }
            return flag;
        }
    }
    bool canJump(vector<int>& nums) { return recc(nums, 0); }
}; 
 /* approach 2  using the bottom up approach .
  the intution  is tha we are standing at the 0 idx  s owe can reach 
  at the present idx  then move next  then we look if we can reach 
    at the  cureent idx  by travese at the  previos idx  if they are
    true and  their number  is greater than the cureent  idx then we can be thier and forward .
    */ 
    /* time complexity 0(n^2).
        space complexity 0(n).*/
   class Solution {
public:
    bool canJump(vector<int>& nums) {
        //bottom up approach.
         int n = nums.size();
          vector<bool>dp(n , false);
           dp[0] = true;
            for(int i=1 ; i<n ; i++)
            {
                  for(int j = i-1 ; j>= 0 ; j--)
                  {
                     if( j+nums[j] >=i && dp[j]==true)
                     {
                         dp[i] = true;
                          break;
                     }
                  }
            } 
             return dp[n-1];
    }
};