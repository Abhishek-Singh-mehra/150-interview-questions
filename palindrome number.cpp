/*Given an integer x, return true if x is a palindrome, and false otherwise.*/ 
 /*********************************** approach 1 ***************************** */ 
  /* the intution is that we will make  the number by divided  the original number a and geting modular of it  and then compare i t if 
  they are equal  then   return true other wise false .*/

  /* time complexity O() 
  space complexity O(1)
   leetcode link = https://leetcode.com/problems/palindrome-number/description/?envType=study-plan-v2&envId=top-interview-150*/

   class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false; 
        long num = x;
        long  copy =0;
         while(x>0)
         {
             int a = x%10;
             copy =(copy*10)+a;
             x =x/10;
         }
          return (copy ==num)? true:false;
    }
};