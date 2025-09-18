/*Given an integer array nums and an integer k,
 return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.*/

/**********************************approach 1 ******************************** */
/* the intution  is that we make a map whit he number and the latest idx of that number bcoz  storing the latest  idx will ensure tha
 i !=j and in theabs(i-j)<=k will eb easy  for us to get. if full filling these
  two conditions return true .*/
/* time complexity 0(n)
 space compleixty 0(1)
  leetcode link =https://leetcode.com/problems/contains-duplicate-ii/?envType=study-plan-v2&envId=top-interview-150*/
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (mp.count(nums[i]))
            {
                if (i - mp[nums[i]] <= k)
                    return true;
            }
            mp[nums[i]] = i; // Always update the index
        }
        return false;
    }
};
