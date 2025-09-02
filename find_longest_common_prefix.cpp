/*Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"*/
 
 /* approach 1 .
   pick the first string and then start comaparing 
    its each element  with the every  element of  the other string   of smae indx.
     if not same then stop  we gert our answer if sme push to the  ans move forward .*/
      /* time complexity 0(n*m  n = length of  vector , m =  length of each string .
       space  complexity  0(1)
        solution link  = https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150
         watch video  = https://www.youtube.com/watch?v=VTr3Nh7BadI*/

      
     class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans ="";

         for (int i=0 ; i< strs[0].length() ; i++)
         { 
               char c = strs[0][i];
                bool match  = true ;
              for (int j= 1 ; j< strs.size() ; j++)
              { 
                 // mismatch if not  equal.
                 if(c != strs[j][i]  || strs[j].length()<i)
                 {
                     match = false ;
                      break ;
                 }
              } 
              if(match == false )
              {
                 break;
              }
               else 
               {
                 ans.push_back(c);
               }
         }
         return ans;
    }
};