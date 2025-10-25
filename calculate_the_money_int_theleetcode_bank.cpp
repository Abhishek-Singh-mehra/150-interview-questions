/*Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.

He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.

Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.*/ 
/*********************************** approach 1 ****************** */ 
/* time complexity O(n)
 space complexity O(1).
  leetcode link = https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/?envType=daily-question&envId=2025-10-25*/ 

  class Solution {
public:
    int totalMoney(int n) {
        int  totalmoney =0;
         int  weekstart =1 ;
          for(int i=0 ; i< n ; i++) 
          {
             totalmoney += weekstart+(i%7);
              if( i%7 ==6) weekstart++;
          } 
           return totalmoney;
    }

};