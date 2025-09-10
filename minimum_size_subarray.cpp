/*Given an array of positive integers nums and a positive integer target,
return the minimal length of a subarray whose sum is greater than or equal to target.
If there is no such subarray, return 0 instead.
 */
/* *************************approach1 *****************************
 brute force approach
  get all the subarray and check if its equal or greater than the target if yes
   then get the size of  subarry .*/
/* time complexity 0(n^2)
 time complexity 0(1). */
class Solution
{
public:
    int checksubarray(int i, int j, vector<int> &nums, int target)
    {
        int sum = 0;
        for (int k = i; k <= j; k++)
        {
            sum += nums[k];
        }
        if (sum >= target)
            return j - i + 1;
        return INT_MAX;
    }
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int res = INT_MAX;
        int n = nums.size();
        // brute force approach get all subaray and check.
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i;
            while (j < n)
            {
                int len = checksubarray(i, j, nums, target);
                if (res > len)
                    res = len;
                j++;
            }
        }
        return (res == INT_MAX) ? 0 : res;
    }
};

/**********************************approach 2 **********************************/

/*  we will create the window of size 1 and get the sum if the sum >= target
  we have to minimize the size so we shrink  the  window  else smaller then increase window .*/
/* time complexity 0(n)
 space complexity 0(1).
  leetcode link = https://leetcode.com/problems/minimum-size-subarray-sum/?envType=study-plan-v2&envId=top-interview-150*/
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int res = INT_MAX;
        int i = 0;
        int j = 0;
        int sum = 0;
        while (j < n)
        {
            sum += nums[j];
            while (sum >= target)
            {
                res = min(res, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return (res == INT_MAX) ? 0 : res;
    }
};
