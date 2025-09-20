/*There are some spherical balloons taped onto a flat wall that represents the XY-plane.
 The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. 
 You do not know the exact y-coordinates of the balloons.
Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. 
There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
 */
 
 /* *************************** approsch1 **************************************/
 /* the intution is that we have to get  he minimum so  we look closely we find that bollons who ovelap can use the common arrow so we can sort it 
  then we clearly see that we can  thethe common arrow and number of the ballonsget bust  then  simply check the condition that  xistart <= x <=xi end 
   other wise we have to use other arrow .*/
    /* time compleixty  o(nlogn + n/2) = nogn 
     space complexity 0(1).
      leetcode link = https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=top-interview-150*/ 
       
      class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n  = points.size();
         sort(begin(points) ,end(points));
         int count= 1;
         
         
        vector<int>prev= points[0];
        for(int i =1 ; i<n ; i++)
         {

             int curr_start = points[i][0];
             int curr_end = points[i][1]; 

              int prev_start =  prev[0];
               int prev_end = prev[1]; 

                 if(curr_start > prev_end)
                 {
                      //no overlapping.
                     count++;
                     prev = points[i];
                 } 
                  else
                  {
                   // means overlapping. 
                    prev[0] = max(prev_start , curr_start);
                    prev[1] = min(prev_end , curr_end);  
                  }
         } 
          return count ; 
    }
};