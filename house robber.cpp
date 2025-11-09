/*You are a professional robber planning to rob houses along a street.
 Each house has a certain amount of money stashed, 
 the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.
 */ 

 /**********************************approach 1 ******************************* */
  /* the intution is that we will pick the house that we have to robb and left the other adjacent house and lastly fet the maxin=mum
    profit from the hoses.*/
     /* time complexity O(2^n)*/

     class Solution {
public:
 int rec(vector<int>&nums   , int index , int n)
 {
     if( index >=  n) return 0;
     int robehouse = nums[index] +rec(nums , index +2 , n); // robing the house .
      int skiphouse =  rec(nums , index+1 , n); //skipping the house .
       return max( robehouse , skiphouse);
        
 }
    int rob(vector<int>& nums) {
         int n = nums.size();
         return (rec(nums ,  0,  n));
    }
}; 


/************************************ approach 2 *********************************** */
/* the intution is that we can use the bottom up approach as we can  store the maximum till the house we are adding  or staying 
 from the previous houses and move forward .*/
  /* time complexity O(n)
     space complexity O(n)
      leectcode link = https://leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=top-interview-150*/
      

      class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
         if(n==0) return 0;
         if(n==1) return nums[0];
         vector<int>dp(n); // to store the max amount  at each house .
         dp[0] = nums[0];
          dp[1] = max(nums[0] , nums[1]);

          for(int i=2 ; i<n ; i++)
          {
             dp[i] = max(dp[i-1] ,dp[i-2]+nums[i]);
          }
           return dp[n-1];
    }
};


