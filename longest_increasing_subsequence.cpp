/*Given an integer array nums, return the length of the longest strictly increasing subsequence.*/ 

/********************************************* approach 1 ******************************* */
/*  we can use the recurssion as we have the choic in every number first to pick if only if its greater then the previous one and the other is 
 to skip it  we will use this logic to  write the ans  the base ase will be if we reach at last  then return the 0 */ 
 /* time complexity O(2^n)
    space complexity O(h)*/

    class Solution {
public: 
    int solve(int indx , int prev ,vector<int>&nums)
    {
         if(indx == nums.size()) return 0;
         int skip = solve(indx+1 , prev , nums);
          int take =0;
           if(prev ==-1 || nums[indx]>nums[prev])
              take =1+solve(indx+1 ,indx ,nums);
        return max(take ,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        return  solve(0, -1 , nums);
    }
}; 


/********************************* approach 2 ************************************* */
/* we will use the bottom up approach .
   as very element is the valid candidate for the sequence   so will wil travese the array and  look the number 
   till  if its the valid cahin contributer and add it to the cain*/
   /* time complexity o(n^2)
      space complexity O(n)*/
      class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         int n  = nums.size() ;
          vector<int>dp(n , 1);
         for ( int i =1  ;i<n  ;i++)
         {
             for(int j =0 ; j<i  ;j++)
             {
                 if(nums[j]<nums[i]){
                     dp[i] = max(dp[i] , dp[j]+1);
                 }
             }
         }
         return *max_element(dp.begin() , dp.end());
    }
};