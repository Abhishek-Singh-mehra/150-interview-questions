/*Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
 find two numbers such that they add up to a specific target number.
  Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.*/
/* approach 1
  the idea is like select the a single number and traverse all the rest array
   if get the target then return . */
/* time complexity 0(n^2).
 space complexity 0(1).*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                else if (numbers[i] + numbers[j] == target)
                    return {i + 1, j + 1};
            }
        }
        return {-1, -1};
    }
};

/* approach 2
   as the vector is sorted then we can for the binary searc htechnique,
    if sum is larger than taget then j-- else i++ i will be at 0 and j wil be at last .*/
/* time complexity 0(n/2).
 space complexity 0(1).
 leetcode link =  https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/?envType=study-plan-v2&envId=top-interview-150*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j)
        {
            int total = numbers[i] + numbers[j];
            if (total == target)
            {
                return {i + 1, j + 1};
            }
            else if (total > target)
                j--;
            else
                i++;
        }
        return {-1, -1};
    }
};
