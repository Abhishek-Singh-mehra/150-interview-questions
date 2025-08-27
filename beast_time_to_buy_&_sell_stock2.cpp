/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. 
However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.*/
 /* approach 1
 the approach  simple draw the graph  then aabsorb the stock prices the intutuion is simple if the stock prices 
 is greater than the previous  we should buy  sell the stock and add to  the profit .*/  
  /* time complexity 0(n)
   space complexity 0(1).*/
  class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0;
         for(int i=1 ; i<prices.size() ; i++)
         {
             if(prices[i] >prices[i-1])
             {
                 profit += prices[i]-prices[i-1];
             }
         }
          return profit ;
    }
};