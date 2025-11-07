/*Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.*/ 

/************************************* approach 1 ********************************* */ 
/*the intution is that the number lie between the 1 to the half of that number  so we can do  the binary search  if the mid isequal or
smaller than the above the mid are the possible candidate of the ans other are not and else condition if greater then  the mid small value are 
legitimate candidate . */
/* time complexity O(long(x))
   space complexity O(1)
    leetcode link = https://leetcode.com/problems/sqrtx/description/?envType=study-plan-v2&envId=top-interview-150*/ 

    class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x; 
        int ans =0;
        int left = 1 ; int right = x/2;
         while(left<=right)
         {
             int mid = left +(right -left)/2;
              if( (long long )mid *mid <= x) 
              {
                 ans =mid ;
                 left =mid+1;
              }
              else {
                  right  = mid -1;
              }
         } 
         return ans;
    }
};