/*Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) 
of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).*/
 /* approach 1 . 
  the intution is simple of using the two pointer move i  when it matches with the j 
   at last if i == s.length() reutnr true ,otherwies false .*/ 
    /* time comlexity  0(t.length())
     space complexity 0(1).*/ 
       class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        int i = 0, j = 0;
        if (len2 < len1)
            return false;

        while (i < len1 && j < len2) {

            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == len1;
    }
}; 
 /* approach 2  
     using the recurssion methord. base case if i>s.length( ) true 
     if j>t.lrngth() return false ;
      all are same .
     */  
       /* time  complexity 0(n).
        space complexity 0(n) recurssion stac k.*/
     class Solution {
public: 
  bool recall( int i  ,int j ,  string s , string t)
  {
     if(i==s.length()) return true ; 
      if( j== t.length()) return false ;
      if(s[i]==t[j])   return recall(i+1 , j+1  ,s, t);
      else 
      { 
        return recall(i ,  j+1 ,s, t) ;
      } 
       
  }
    bool isSubsequence(string s, string t) {
        if(s.length()>t.length()) return false ;
          return recall(0 , 0  ,s, t);
    }
};