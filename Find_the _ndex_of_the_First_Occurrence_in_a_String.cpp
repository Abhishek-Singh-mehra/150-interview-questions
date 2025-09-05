/*Given two strings needle and haystack,
return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */
/*  approch 1 .
 the intution is simple do  what question says  step by step think of every case.*/
  /* time complexity 0(n).
   space complexity = 0(1).*/
class Solution
{
public:
    int strStr(string s, string needle)
    {
        int res = -1;
        int j = 0;

        if (s.length() < needle.length()) // if needle is  biger than the s string 
                                         //no ways to get
            return -1;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == needle[j] && j < needle.length())
            {
                if (j == 0)
                    res = i;
                j++; // increment j before checking full match
                if (j == needle.length())
                    return res;
            }
            else
            {
                if (j > 0)
                    i = i - j; // rewind i to retry from next start
                j = 0;
                res = -1;
            }
        }
        return -1;
    }
};
