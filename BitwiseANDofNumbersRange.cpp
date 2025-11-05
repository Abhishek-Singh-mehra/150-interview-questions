/*Given two integers left and right that represent the range [left, right], 
return the bitwise AND of all numbers in this range, inclusive.*/

/* ******************************* approach 1 *********************************/
/* the intution is that we will use the and approach from the left to he right number.*/
/* time complexity O(n)
space complexity O(1)*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
       int sum =0;
        for(int i = left ;i<=right ; i++)  
         { 
            sum ^=i;
         } 
         return sum;
    } 
}; 
 
/******************************** approach 2 ***************************** */
/* the intution is that The bitwise AND of numbers in a range [left, right] only keeps the common prefix bits of left and right.
Once a bit position differs between left and right, all bits to the right of it become 0 in the result.*/
 /* time complexity O(log(n))
  space complexityO(1)
  leetcode link = https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=study-plan-v2&envId=top-interview-150*/
   
  class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        // Find common prefix
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        // Shift back to restore the common prefix
        return left << shift;
    }
};
