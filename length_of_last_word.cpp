/*Given a string s consisting of words and spaces,
return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.*/
/* approach 1
   the intution is simple traverse the string when ever we look the  space  the  reset the length.
   */
/* time complexity  0(n).
  space complexity 0(1).*/
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.length();
        int ans = 0;
        int i = 0;
        while (i < n)
        {
            if (s[i] == ' ')
            {
                // reset the count .
                ans = 0;
            }
            else
            {
                ans++;
            }
            i++;
        }
        return ans;
    }
};
/* the one mistake in this approach is that what  if the last indx of the string is space then ans
 will be 0.
  test case fail .*/
/* approach 2 .
  tis time  we will traverse from the last  if we counter the space then  we will
   ignore it   then start to count the number .*/
/*time compleity 0(1);
 space complexity 0(1).*/

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.length();
        int length = 0;
        int i = n - 1;
        while (i >= 0 && s[i] == ' ')
            i--;
        while (i >= 0 && s[i] != ' ')
        {
            length++;
            i--;
        }
        return length;
    }
};