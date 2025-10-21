/*Given an integer array nums, find the subarray with the largest sum, and return its sum.*/
/************************ approach 1 *************************** */
/*intution is that find all the subarray and get the maximum as the ans .*/
/* time complexity O(n^2)
 space complexity O(1).*/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxsum = INT_MIN;
        int currsum = 0;
        for (int i = 0; i < n; i++)
        {
            currsum = 0;
            for (int j = i; j < n; j++)
            {
                currsum += nums[j];
                maxsum = max(maxsum, currsum);
            }
        }
        return maxsum;
    }
}



/***************************** approach 2  ****************************/
 /* using the kandane's algorithm  to get the maximum subarray .*/
 /* time compleixty O(n)
  space  complexity O(1).
  leetcode link =https://leetcode.com/problems/maximum-subarray/?envType=study-plan-v2&envId=top-interview-150*/

  class Solution {
public:
    int maxSubArray(vector<int>& nums) {  
        int currentSum = nums[0];
        int maxSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};
