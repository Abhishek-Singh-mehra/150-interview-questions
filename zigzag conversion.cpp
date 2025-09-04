/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);*/
/* approach1 .
     solve it by drwaing .

     r0 1           11
     r1 2        10 12
     r2 3      9    13
     r3 4    8      14
     r4 5  7        15
     r5 6           16
       the intution  is simpl first   get to the   bottomsouth part then
       the upper north part  with the formula  check the  edge case too.*/ 
        /* time complexity 0(1) ,bcoz of the const size of row.
            space complexity 0(1).*/ 
             /* leetcode link = https://leetcode.com/problems/zigzag-conversion/?envType=study-plan-v2&envId=top-interview-150
              video refrence = https://www.youtube.com/watch?v=k8F7nzySY60*/
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.length())
            return s;
        string res = "";
        int n = s.length();
        int j, idx1, idx2, a, b;
        bool flag;
        for (int i = 0; i < numRows; i++)
        {
            j = i;
            int dakshin = 2 * (numRows - 1 - i);
            int uttar = 2 * i;
            flag = true;
            while (j < n)
            {
                res.push_back(s[j]);
                if (i == 0)
                {
                    j += dakshin;
                }
                else if (i == numRows - 1)
                {
                    j += uttar;
                }
                else
                {
                    if (flag)
                    {
                        j += dakshin;
                    }
                    else
                    {
                        j += uttar;
                    }
                    flag = !flag;
                }
            }
        }
        return res;
    }
};