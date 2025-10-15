/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.
*/ 
 /************************************************* approach 1 ********************************************* */
  /* the intution is that we use the combination of every step and after that when we reach at the ending of one combination we will backtrack means,
   we will undo the input combination from backsite.*/
    /* time complexity O(n*4^n)
       space complexity O(n)
       leetcode link= https://leetcode.com/problems/letter-combinations-of-a-phone-number/?envType=study-plan-v2&envId=top-interview-150 */ 

       class Solution {
public: 
 void backtrack(const string &digits ,const vector<string>& phoneMap, int index, string& current, vector<string>& result)
 {
if(index == digits.length())
           {
             result.push_back(current);
              return ;
           }
            string letters = phoneMap[digits[index] - '0'];
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, phoneMap, index + 1, current, result);
            current.pop_back();  // Backtrack
        }
        };
 
    vector<string> letterCombinations(string digits)
        {
           
         
          if(digits.empty()) return{}; 
           vector<string>phonemap = 
           {
            "" , "" , "abc","def","ghi","jkl","mno" ,"pqrs","tuv","wxyz"
           };
          vector<string>result ;
          string current ;
          backtrack(digits , phonemap , 0 , current  , result);
           return result ;

    }
};