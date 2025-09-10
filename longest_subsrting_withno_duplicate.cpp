/*Given a string s, find the length of the longest substring without duplicate characters.*/
/* ***********************appraoch 1**********************************/
/* get all the sub strign and check their is duplicate character  if not the n go for the maximum
  to chec kthe duplicate we can store them in the set .*/
/* time complexity 0(n^2)
  space complexity 0(n).*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int n = s.length();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<char> seen;
            for (int j = i; j < n; j++)
            {
                if (seen.count(s[j]))
                    break;
                seen.insert(s[j]);
                res = max(res, j - i + 1);
            }
        }
        return res;
    }
};
/********************approach 2 *********************************** */
/*  the  intution is using the sliding window approach for the particular window and to check the duplicate
we can use the map that store the last indx of the character if its in the windowthen we will  move it . */
/* time complexity 0(n).
 space complexity 0(n).
  leectcode link =https://leetcode.com/problems/longest-substring-without-repeating-characters/?envType=study-plan-v2&envId=top-interview-150*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> charIndex;
        int maxLen = 0, left = 0;

        for (int right = 0; right < s.length(); ++right)
        {
            if (charIndex.count(s[right]) && charIndex[s[right]] >= left)
            {
                left = charIndex[s[right]] + 1;
            }
            charIndex[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
