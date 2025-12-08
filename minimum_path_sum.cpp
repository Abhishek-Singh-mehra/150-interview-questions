/*Given a m x n grid filled with non-negative numbers,
 find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.*/


/********************************************* approach 1 *************************** */
/* the simple we will find all the   path and get the minimum path among them we will use the recursion 
   the base case will eb if we reach at the bottom  then return the grid[i][j]  else if we get out of bound the new  have to get back 
    we can return the maximum number as this path is invalid . */
    /* time complexity O(2^n)
        space complexity O(h)*/
        class Solution {
public: 
int n ;
int m ; 
int solve(int i , int j ,vector<vector<int>>&grid)
{ 
    if(i>=n || j>=m) return INT_MAX; // base case .
     if(i==n-1 && j==m-1) return grid[i][j]; // base case .
     int down = solve(i+1 , j , grid);
      int right = solve(i , j+1 , grid);
       return  grid[i][j]+min(down , right); // min path.
}
    int minPathSum(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
        return solve(0, 0,grid);
    }
};



/*****************************************approach 2 ******************************** */
/* if we can store the minimum path from the starting  at last we can get to the last grid as the minimum path. this is 
the bottom up approach .*/
/* time complexity O(n^2)
   space complexity O(n^2)
   leetcode link = https://leetcode.com/problems/minimum-path-sum/description/?envType=study-plan-v2&envId=top-interview-150*/ 

   class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
         int n = grid[0].size();; 
         vector<vector<int>>dp(m , vector<int>(n)); 
          for(int i =0  ; i<m ; i++)
          {
             for(int j =0 ; j<n  ; j++)
             {
                 if(i ==0 && j ==0){
                     dp[i][j] = grid[i][j];
                 }
                  else if( i==0)
                  {
                     dp[i][j]  = dp[i][j-1] + grid[i][j];
                  }
                  else if( j==0){
                     dp[i][j] = dp[i-1][j] + grid[i][j];
                  }
                   else 
                   {
                     dp[i][j] = grid[i][j] + min(dp[i-1][j] ,dp[i][j-1]);
                   }
             }
          } 
           return dp[m-1][n-1];
    }
};