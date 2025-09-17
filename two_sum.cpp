/*Given an array of integers nums and an integer target,
 return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution,
 and you may not use the same element twice.
You can return the answer in any order.
 */
/*********************approach 1*************************** */
/* the intution is that use the two pointer if we find the sum of i and j
 to be equal to the target then return their idex. */
/* time cimplexity 0(n^2).
 space complexity 0(1).*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> ans(2, 0);
        for (int i = 0; i < n; i++)
        {
            int compliment = target - nums[i];
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                else if (nums[j] == compliment)
                {
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
            }
        }
        return ans;
    }
};

/* ************************approach 2 ****************************/
/* the intution is that  we use the hashmap to store the value and its idx
 if we found the compliment number in the map we will return the number and the
  compliment num idx  other wise we will insert the number  with the idx .*/
/*  time compleixty 0(n).
 space complexity 0(n).
 leetcode link = https://leetcode.com/problems/two-sum/description/?envType=study-plan-v2&envId=top-interview-150*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans(2);
        unordered_map<int, int> hashmap;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int compliment = target - nums[i];
            if (hashmap.find(compliment) != hashmap.end())
            {

                ans[0] = hashmap[compliment];
                ans[1] = i;
                return ans;
            }
            hashmap[nums[i]] = i;
        }
        return ans;
    }
};