/*Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest.
 Converting a decimal place value into a Roman numeral has the following rules:
If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input,
append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol,
 for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used:
  4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L),
 or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.
*/
/*  approach 1 .
 the intution  is that we  first work  to get the number highest that we can divide
  it then intert that number to string , do this process untill the number si greater than the 0.  */
/* leetcode problme  link = https://leetcode.com/problems/integer-to-roman/?envType=study-plan-v2&envId=top-interview-150 */
/*  time complexity  0(1) bcoz of constant iteratinon 13
 space complexity 0(1).*/
class Solution
{
public:
    vector<int> vec = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> cvec{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string intToRoman(int num)
    {
        string result = "";
        for (int i = 0; i < 13; i++)
        {
            if (num == 0)
            {
                break;
            }
            int times = num / vec[i];
            while (times--)
            {
                result += cvec[i];
            }
            num = num % vec[i];
        }
        return result;
    }
};