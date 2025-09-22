/*You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 */

/************************approach 1 *************************** */
/* the idea is that if we encounter the + - * or / we will extract the top two elemnt and do the operation and push it to the stack.
 if not then simplely push it to the stack lastly return the top of the stack.*/
/* time compleixty O(n)
 space compleixty O(k) ot O((n/2)-1)
  leetcode link = https://leetcode.com/problems/evaluate-reverse-polish-notation/?envType=study-plan-v2&envId=top-interview-150 */

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int i = 0;
        stack<int> st;
        while (i < tokens.size())
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (tokens[i] == "+")
                {
                    st.push(a + b);
                }
                else if (tokens[i] == "-")
                {

                    st.push(b - a);
                }
                else if (tokens[i] == "*")
                {

                    st.push(a * b);
                }
                else
                {
                    st.push(b / a);
                }
            }
            else
            {
                int num = stoi(tokens[i]);
                st.push(num);
            }
            i++;
        }
        return st.top();
    }
};