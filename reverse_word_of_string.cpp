/*Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.*/
 /* approach 1 . 
  the intution is that first reverse the  the whole strig
   then  iterate in the  string find the space " " then  before the space ,reverse the string 
     do same  with  the rest  of the string.  */
      
     class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end()); // reverse the whole sting .
         int i=0 ;
          int left =0;
           int right = 0;
            while( i<s.length())
            {
                while(i< s.length() &&  s[i]!=' ')
                {
                     s[right] =s[i];
                      i++;
                      right++;
                } 
                 if( left<right)
                 {
                     reverse(s.begin()+left , s.begin()+ right); 
                     s[right] =' ';
                     right++;  
                     left = right;
                 }
                  i++;
            } 
             return s.substr( 0,right-1);
    }
};