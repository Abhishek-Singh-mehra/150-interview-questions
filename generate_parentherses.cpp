/*Given n pairs of parentheses,
 write a function to generate all combinations of well-formed parentheses.*/ 
   
 /********************** approach 1 ************************ */ 
  /* the approach  the ans will be of size 2*n number of parentherses  right the base case will be the if size == 2*n means we get a valid parentheses
     and to move to the parentheses if open bracket is <nmenas we can generate more open brackets and move forward ,and  for the closing we
     can say that if cllsing are smaller than opening bracket that menas we  can generate more brackets . */ 
      
     /* time complexity O(n!)
       space complexity O(2*n)
       leetcode link = https://leetcode.com/problems/generate-parentheses/description/?envType=study-plan-v2&envId=top-interview-150*/ 

       class Solution {
public:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        if (current.length() == 2 * n) { // Base case: Fully built
            result.push_back(current);
            return;
        }

        if (open < n) backtrack(result, current + "(", open + 1, close, n); // Add '(' if possible
        if (close < open) backtrack(result, current + ")", open, close + 1, n); // Add ')' only if valid
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};