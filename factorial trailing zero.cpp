/*Given an integer n, return the number of trailing zeroes in n!.
Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.*/ 

/* ******************************** approach 1 ***************************/
/* as we know in the number when we can get teh zero if it  is multiply by 5 so what we will do is that we will 
 divide the number by 5 and add the num to the ans and multiple the i by its power.*/
 /* time complexity O(log(n))
   space complexity O(1)
    leetcode link = https://leetcode.com/problems/factorial-trailing-zeroes/description/?envType=study-plan-v2&envId=top-interview-150*/ 

    class Solution {
    public:
    int trailingZeroes(int n) {
         int count = 0;
        for (int i = 5; n / i >= 1; i *= 5) {
            count += n / i;
        }
        return count ;
    }
};