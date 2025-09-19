/*Given an array of intervals where intervals[i] = [starti, endi],
 merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].*/ 

 /********************************approach1 ************************** */
  /* intution is that we will compare the nums[i][1] with the nums[i+1][0] if they  1 st is greater than the 2nd the nmerge them  by
   getting maximum  of these two in the 1 st then move forward if not then the range not to be change and pus to ans ,
    and to compare  with te previous  we need to make sure they are in sorted order .*/ 
     /* time complexity 0(n/2)
      space compleixty 0(1).
      leetcode link  =https://leetcode.com/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-interview-150
      */
     class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res; 
         sort(intervals.begin()  , intervals.end());
         res.push_back(intervals[0]);
           for(int i=1 ; i< intervals.size() ; i++)
           {
             vector<int>&last = res.back(); 
              if(intervals[i][0] <=last[1])
              {
                last[1] = max(last[1] , intervals[i][1]);
              }
               else 
               {
                 res.push_back(intervals[i]);
               }
           }
        return  res;
    }
};