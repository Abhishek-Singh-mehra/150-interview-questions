/*Given a string s, return the longest palindromic substring in s.*/ 

/********************************* approah 1 ******************** */
/* the intution is tha we will iterate the strign and get all the substrign and check if they are 
palindrome then insert it to the naser and get the longest palindrome*/
/* time complexity O(n^3)
   space complexity O(n)*/

   class Solution {
public:
    bool checkpali(int i , int j , string s)
    {
         int start =i,end =j;
          while(start<=end)
          {
             if(s[start]!=s[end]) return false;
             start++;
             end--;
          }
          return true;
    }
    string longestPalindrome(string s) {
        int n = s.length(); 
        string ans;
        for(int i=0 ; i<n ; i++)
        {
             for(int j=i; j<n ; j++)
             {
                  if(checkpali(i ,j ,s) && ans.length()<(j-i)+1)
                  {
                      ans = s.substr(i,j-i+1);
                    }
             }
        }
        return ans;
    }
}; 


/************************************** approach 2 ******************************* */
/* the intution is that we will make the 2d array and store the longest subarray with the palindrome
 till that index*/
 /* time complexity O(n^2)
    space complexity O(n^2)
     leetcode link = https://leetcode.com/problems/longest-palindromic-substring/description/?envType=study-plan-v2&envId=top-interview-150*/ 

     class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLen = 1;

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; ++i)
            dp[i][i] = true;

        // Check substrings of length 2
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Check substrings of length >= 3
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};