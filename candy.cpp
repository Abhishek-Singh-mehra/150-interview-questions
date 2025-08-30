/*There are n children standing in a line. 
Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.*/
 /* approach 1 
   i have looked this question on  youtube and  i found a  good video that explain 
     this in simple manner 
      intution is that  minimum candy given to every one is 1  so we will 
       traverse from left to right and check left side of every student  and 
        full fill the conditons  
         then  traversal from the right to left   and look to the right  and full fill
          the codition then at last  sum of all the maximum value of candy given 
           to every student .*/
           /* video link https://www.youtube.com/watch?v=YUT13Koh5Jg thanks to sir .*/
            /* time complexity 0(n).
               space complexity 0(n).*/
         
           class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
         vector<int>l2r(n ,1);
          vector<int>r2l(n ,1);
           // first  look at the left side. 
           for(int i=1 ; i<n ; i++)
           {
              if(ratings[i]>ratings[i-1])
              {
                  l2r[i] = l2r[i-1] +1;
              }
           }
            //now look at the right side .
            for(int j= n-2 ; j>=0 ; j--)
            {
                  
                  if(ratings[j]>ratings[j+1])
                  {
                     r2l[j] = r2l[j+1]+1;
                  }
            } 
             int ans = 0; 
              // getting the maximum  candy of every student .
              for(int i=0 ; i<n ; i++)
              {
                 ans +=max(l2r[i] , r2l[i]);
              } 
               return ans ;
    }
};