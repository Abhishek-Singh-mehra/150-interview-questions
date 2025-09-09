/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.*/
/* approach 1
  ************************the brute force approach*******************************
    we use two sum approach in the ineer way and the one for loop  outside to get  the
     3 sum and check or the  target number .
  */
/* time complexity 0(n).
 space complexity 0(1). 
  leetcode link = https://leetcode.com/problems/3sum/description/?envType=study-plan-v2&envId=top-interview-150*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // Sort the input array first

        for (int i = 0; i < nums.size(); i++)
        {
            // Skip duplicate elements for `i`
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0)
                {
                    // Found a triplet
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicate elements for `j`
                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    // Skip duplicate elements for `k`
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
                else if (sum < 0)
                {
                    j++; // Move `j` to the right to increase the sum
                }
                else
                {
                    k--; // Move `k` to the left to decrease the sum
                }
            }
        }

        return ans;
    }
};