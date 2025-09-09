/*You are given an integer array height of length n.
 There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container,
 such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.*/ 
 /* approach 1
    using two pointer approach we put the 
    i at 0 and j at the last  then we compute the area how by the width 
     by j-i and the height  will be min of height[i] , height[j].
      after computing the area if its more then the stored area then replace with new area . */
       /* time complexity 0(n/2).
        space complexity 0(1). 
         leetcode link  = https://leetcode.com/problems/container-with-most-water/submissions/1764967465/?envType=study-plan-v2&envId=top-interview-150*/
        class Solution {
public:
    int maxArea(vector<int>& height) {
        int  area =0;
         int i=0;
          int j= height.size()-1 ;
           int diffrence =0 ;
           int copy=0;
         while(i<=j)
         {
              diffrence =  j-i;
              if( height[i]>height[j])
              {
                  copy = min(height[i],height[j]) * diffrence;
                   if(area <copy )
                   {
                     area = copy ;
                    
                   }
                    j--;
              }
               else
               {
                   copy =  min(height[i],height[j]) * diffrence;
                   if(area <copy )
                   {
                     area = copy ;
                    
                   }
                    i++;
               }
         } 
         return area;
    }
};