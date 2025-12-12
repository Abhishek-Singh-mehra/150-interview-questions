/*Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.*/ 


/* ****************************************************** approach 1 ***************************************************/
/* the intution is  that  we will put the pointer on each of the s and check if thes1[i]==s3[k] eans we get one thing  we move forward if s2[j]==s3[k] we also move forward 
the pointer j and k at last if we gat the k  i and j out of the bound menad all the sequence is used return true  if not then false , recurssion approach .*/
/* time comlexityO(2^n*m)
   space complexity O(h)*/

   class Solution {
public:  int n ,m ,a;
  bool solve( int i , int j , int k,string s1 ,string s2 ,string s3)
  {
     if(i==n && j==m && k==a) return true ;
      if(k>=a) return false ; 
      bool result =false ;
       if(i<n && s1[i]==s3[k])result  = solve( i+1 ,j ,k+1 ,s1 ,s2 ,s3);
         if(result ==true ) return true;
         if(j<m && s2[j]==s3[k]) result = solve(i ,j+1 ,k+1 ,s1, s2,s3);
         return result ;
  }
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.length();
        m = s2.length();
        a= s3.length();
        return solve(0,0,0,s1 ,s2 ,s3);

    }
};



/*********************************************** approach 2 ************************************** */
/* we can use the memorization we can store these in the 3d vector if we get the same in the interval/traversing we will directly pick from
 then only not to traverse further  */
 /* time complexity O(n*m)
    space complexity O(n*m*k)
     leetcode link = https://leetcode.com/problems/interleaving-string/description/?envType=study-plan-v2&envId=top-interview-150*/

    
     class Solution {
public:
    int m, n, N;
    int t[101][101][201];
    
    bool solve(int i, int j, int k, string& s1, string& s2, string& s3) {
        
        if(i == m && j == n && k == N) {
            return true;
        }
        
        if(k >= N) //other string didn't get consumed at all
            return false;
        
        if(t[i][j][k] != -1)
            return t[i][j][k];
        
        bool result = false;
        
        if(i < m && s1[i] == s3[k]) {
            result = solve(i+1, j, k+1, s1, s2, s3);
        }
        
        if(result == true)
            return t[i][j][k] = result;
        
        if(j < n && s2[j] == s3[k]) {
            result = solve(i, j+1, k+1,s1, s2, s3);
        }
        return t[i][j][k] = result; 
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        N = s3.length();
        memset(t, -1, sizeof(t));
        return solve(0, 0, 0, s1, s2, s3);
    }
};
