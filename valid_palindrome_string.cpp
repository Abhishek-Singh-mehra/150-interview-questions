/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
 it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.*/
 /* approach  1 
   simple intution is that  first check the   string have spacial character 
    if not then push it to the temp strin then 
     call the function  ispalindrome  which return true if not palindrome else false .*/ 
       /* time complexity 0(n).
         space complexity 0(n). 
          leetlcode link =https://leetcode.com/problems/valid-palindrome/?envType=study-plan-v2&envId=top-interview-150*/
     class Solution {
public:
    bool checkpalindrome(string temp) {
        int len = temp.length();
        int i = 0;
        int j = len - 1;
        while (i < j) {
            if(temp[i] != temp[j])return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string temp;
        for (auto ch : s) {
            if (isalnum(ch))temp += tolower(ch);
        }
        return checkpalindrome(temp);
    }
};