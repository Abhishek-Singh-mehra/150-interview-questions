/*Given a string s representing a valid expression, implement a basic calculator to evaluate it, 
and return the result of the evaluation.
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
 */

 /*************************************approach 1 ********************************** */ 
  /* the intution is thhat we use the res sign and the number variable for the process and when ever we encounter  the bracket we will use the stack 
   and reset the variable to 0 and +ve then solve the bracket and add /subtract it with the number at stack .*/
    /* leetcde link = https://leetcode.com/problems/basic-calculator/description/?envType=study-plan-v2&envId=top-interview-150
     video link = https://www.youtube.com/watch?v=3AEKyHx3tzU 
      time complexity  O(n)
      space complexity 0(n). */ 
      
     class Solution {
public:
    int calculate(string s) {
         stack<int> st;
        int number = 0;
        int result = 0;
        int sign   = 1;
        
        for(int i = 0; i<s.length(); i++) {
            if(isdigit(s[i])) {
                number  = 10*number + (s[i] - '0');
            } else if(s[i] == '+') {
                result += sign*number;
                number  = 0;
                sign = 1; //For further
            } else if(s[i] == '-') {
                result += sign*number;
                number  = 0;
                sign = -1; //For further
            } else if(s[i] == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            } else if(s[i] == ')') {
                result += sign*number;
                number = 0;
                int top = st.top(); st.pop();
                result *= top;
                top = st.top(); st.pop();
                result += top;
            }
        }
        result += (sign*number);
        return result;
    }
};