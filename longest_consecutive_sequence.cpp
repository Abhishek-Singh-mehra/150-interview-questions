/*Given an unsorted array of integers nums,
return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.*/
/**************************************approach 1 ********************************* */
/* the idea is all the number have possibility that they can be the sequencial number part  so we use map and put them true in the stating
 then if we look closely the number which have the number and the (number-1) int the map then the number is no longer the starting of these
 sequence then we can  make it false .lastly we can  count the max by
  traversling it to the map.*/
/* time complexity 0(n).
 space compleixty 0(n).
 leetcode link = https://leetcode.com/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-interview-150*/

class Solution
{
public:
    int findLength(const unordered_map<int, bool> &mp, int k)
    {
        int ans = 0;
        while (mp.find(k) != mp.end())
        {
            ans++;
            k++;
        }
        return ans;
    }

    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, bool> mp;
        // first make  them all true ;
        for (int &i : nums)
        {
            mp[i] = true;
        }
        // now  make false whose smallernum is notpresent.
        for (int &num : nums)
        {
            if (mp.find(num - 1) != mp.end())
                mp[num] = false;
        }

        // now find the maxlen by reversing the like 4 3 2 1 .
        int maxlen = 0;
        for (auto &[key, isStart] : mp)
        {
            if (isStart)
            {
                maxlen = max(maxlen, findLength(mp, key));
            }
        }
        return maxlen;
    }
};