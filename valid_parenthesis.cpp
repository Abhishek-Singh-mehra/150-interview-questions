/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/

/*  ****************************** approach 1 ********************************/
/* the intution is that we can use the stac kto look into  the previous symbol.
 so if we encounter teh opening bracket we will push to stack  , if we encounter the closing bracket then look the top of stac kif it matches with
  opposite bracket then pop  from the stack  other wise return false .at last if the stac kis empty then return true .*/
/* time complexity O(n)
   space complexity O(n)
    leetcode link = https://leetcode.com/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-interview-150*/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (char &ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                stk.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']')
            {
                // pop  from the stack.
                if (stk.empty())
                {
                    return false;
                }
                // Check if the top of the stack matches the closing bracket
                char top = stk.top();
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                {
                    return false; // Mismatched bracket
                }

                stk.pop();
            }
        }
        if (stk.empty())
        {
            return true;
        }
        return false;
    }
};