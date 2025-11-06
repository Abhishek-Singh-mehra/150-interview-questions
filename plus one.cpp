/*You are given a large integer represented as an integer array digits,
 where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. 
 The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.*/  


/******************************************* approach 1******************************************** */ 
/* the intution is that we will move from the right hand side and add one to the last number if it exceeded than 10 or equal to1o 
we will move it to left side and add to that number by one.*/
 /* time complexity O(n)
    space complexity O(1)
    leetcdoe problem = https://leetcode.com/problems/plus-one/description/?envType=study-plan-v2&envId=top-interview-150*/ 

    class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
     {
       for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + 1 != 10) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
            if (i == 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
        return digits;        
    }
   
};