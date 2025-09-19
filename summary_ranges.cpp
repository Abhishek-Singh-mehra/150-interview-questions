/*You are given a sorted unique integer array nums.
A range [a,b] is the set of all integers from a to b (inclusive).
Return the smallest sorted list of ranges that cover all the numbers in the array exactly. 
That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 */
 /* *********************************approach 1***************************/
 /*the intution is that first we have to convert the num to the string then  iterate
   forward  and find the nosequence or cut  the n push it to the ans string 
    and the edge case would be if the i and thej value are same then we have 
    to insert the one value only .*/
    /* time complixty 0(n)
    space complexity 0(1).
    leetcode link = https://leetcode.com/problems/summary-ranges/?envType=study-plan-v2&envId=top-interview-150 */ 
    class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
         string a  , b;
          int i =0;
           vector<string>res ;
           while(i <nums.size())
           { 
              a = to_string(nums[i]);
              int j= i+1 ;
               while( j <nums.size()  && nums[j] == nums[j-1]+1) //check the  break .
               {
                 j++;
               } 
                 b = to_string(nums[j-1]); 
                 if(a==b) res.push_back(a); 
                 else 
                 {
                    res.push_back(a+"->" + b); //format to insert .
                 }
                  i =j;
           } 
            return res ;
    }
};