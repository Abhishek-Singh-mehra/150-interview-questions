/*Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).*/ 
/* *********************************** approach 1 ********************/ 
/*the intution is that we can directly use the in build function __builtin_popcount(n) and their is also another 
one which is we will iterate and do the right shift by i times and then do theand operation with the 1 if we get the one that means that
iterator i have the no of one in it . */
 /* time complexity O(1)
   space complexity O(1)
   leetcode link = https://leetcode.com/problems/number-of-1-bits/description/?envType=study-plan-v2&envId=top-interview-150*/

   class Solution {
public:
    int hammingWeight(int n) {
        int count =0;
         for(int i=0; i<32 ; i++)
         {
             if((n>>i)&1) count++;
         }
         return count ; 
    }
};





