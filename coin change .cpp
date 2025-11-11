/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.*/ 


/************************ approach 1 **************************** */
/* we  cna use the  bottom up approach  for this as for the  0 coin or money we need the  0 coin  and for the 
 1  money we can get the   voin from  the min from the present coin  and the previous coin*/
 /* time complexity O(n^2)
    space complexity O(n)
     leetcode link = https://leetcode.com/problems/coin-change/description/?envType=study-plan-v2&envId=top-interview-150*/ 

     class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         vector<int> dp(amount + 1, INT_MAX);
         dp[0] = 0; // Base case: 0 coins needed for amount 0

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};