/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

/*approach 1.
the intution issimple  that we assume that we buy that first stock if the  next stock is high then the previous.
 we will buy and get the netprofit  and  if the stock is low then  sell  it so we get the netprofit if thenetprofit its greater 
then the profit we will put the  net profit to the profit .*/
 /* time complexity 0(n).
   space complexity 0(1).*/
   class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        if( n <2)
        {
             return 0;
        }
          int buy = prices[0];
          int profit =0;
           int netprofit =0;
            for(int i=1 ; i<n ; i++)
            {
                 if( buy >prices[i])
                 {
                     buy = prices[i];
                 } 
                  netprofit = prices[i]-buy ;
                   if( netprofit>profit)
                   {
                     profit = netprofit;
                   }
            } 
             return profit ;
    }
};