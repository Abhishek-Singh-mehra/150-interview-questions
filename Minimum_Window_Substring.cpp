/*Given two strings s and t of lengths m and n respectively,
 return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring,
 return the empty string "".
The testcases will be generated such that the answer is unique.*/
/* ***************************************************approach1*************************************************/
/* intution is that Use a sliding window (two pointers: left and right) to explore substrings of s.
Expand the window to include required characters, and contract it to find the minimum possible valid window. */
/* time complexity 0(n).
   space complexity 0(n).
    leetcode link =https://leetcode.com/problems/minimum-window-substring/?envType=study-plan-v2&envId=top-interview-150*/
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> need, window;
        for (char c : t)
            need[c]++;

        int left = 0, right = 0, valid = 0;
        int start = 0, len = INT_MAX;

        while (right < s.size())
        {
            char c = s[right++];
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            while (valid == need.size())
            {
                if (right - left < len)
                {
                    start = left;
                    len = right - left;
                }
                char d = s[left++];
                if (need.count(d))
                {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
