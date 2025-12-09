/*You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.*/ 

/*******************************approach 1 *************************** */
/* the intution is that we will get all the path that we can reach to the right bootom once reached 
return 1 if not the nreturn 0.*/
/* time complexity O(2^n)
   space complexity O(h)*/
   class Solution {
public:  
int n ;
int m ;
    int solve(int i , int j , vector<vector<int>>&grid)
    {
         if(i==n-1 && j==m-1 ) return 1; // we reach at the destination. 
         if(i>=n ||j>=m || grid[i][j]==1) return 0;
      
         int  right =solve(i , j+1 , grid); //right move

         int left = solve(i+1 , j , grid); //down move 
          return left+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         n= obstacleGrid.size();
         m= obstacleGrid[0].size();
           if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        return solve(0 , 0,obstacleGrid);
    }
};


/******************************* approach 2 *************************************** */
/* the intution is simple we will store the path in the 2 d vector array if we get that we 
are getting the path again then we will return the value of that indx  by this we will minimze the 
  iteration.*/
  /* time complexity O(n.m)
     space complexity O(n.m)
     leetcode link = https://leetcode.com/problems/unique-paths-ii/description/?envType=study-plan-v2&envId=top-interview-150*/
     class Solution {
public:
 int n;
  int m;
   vector<vector<int>>dp;
    int solve(int i , int j, vector<vector<int>>&grid)
   {
     if(i>=n ||j>=m || grid[i][j]==1) return 0;
     if(i==n-1 && j==m-1) return 1 ;
     if(dp[i][j]!=-1) return dp[i][j];
     int right = solve(i ,j+1 ,grid);
     int down = solve(i+1 ,j , grid);
     return dp[i][j] = right +down;
   }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n= obstacleGrid.size();
         m = obstacleGrid[0].size();
          if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
          dp.assign(n,vector<int>(m,-1));
          return  solve(0,0,obstacleGrid);
    }
};