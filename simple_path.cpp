/*You are given an absolute path for a Unix-style file system, which always begins with a slash '/'.
 Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.

 */
 /* ****************************approach 1 *****************************/
 /* the approach i that we first extract  the  token  seprated by '/'  then we  travel  through the token  if the toekn .. shows thats means pop the 
    fron the stack and  apart from the . / the alphabet should be push to the stack .lastly pop the stack andstore in the strign and reverse it .
      */
      
      /* time complexity 0(n).
       space compleity O(k).
       leetcode link = https://leetcode.com/problems/simplify-path/?envType=study-plan-v2&envId=top-interview-150*/ 

       class Solution {
public:
    string simplifyPath(string path) {
        string token ="";
         stringstream ss(path); 
          stack<string>st;
          while( getline(ss, token , '/')){
               if(token =="" || token == ".") continue ;
                if(token !="..") st.push(token);
                else if(!st.empty()) st.pop();
          }
           string res ="";
            while(!st.empty())
            {
                 res = "/"+st.top() +res ;
                 st.pop();
            } 
             if(res.length()==0)
             {
                 res ="/";
                
             } 
              return res ;
    }
};