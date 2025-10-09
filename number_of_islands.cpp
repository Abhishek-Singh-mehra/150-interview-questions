/*Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 You may assume all four edges of the grid are all surrounded by water.*/
 /********************************** approach 1 ***************************************** */ 
  /* the intution is that we will traverse the grid and find the land with 1 and do the dfs menas the land with are connected to that land
   manes that  they are teh part of the isalnd  and mark them with special symbol #  v and count the island when we get the new island after the 
   dfs of one island .*/
    /* time complexity O(n*m)
      space complexity O(n*m)
       leetcode problem  = https://leetcode.com/problems/number-of-islands/?envType=study-plan-v2&envId=top-interview-150*/ 

       class Solution {
public: 
    int n=0 ;
     int m=0 ;
    void  dfs(vector<vector<char>>&grid , int i , int j)
    {
         //base case .
          if(j>=m || i>=n || i<0 || j<0|| grid[i][j]=='0' || grid[i][j]=='#')return ;  //base condition 
           grid[i][j]= '#'; //change the symbol 
            dfs(grid , i+1 , j);//recurssive call.
            dfs(grid ,i-1 ,j);
             dfs(grid, i, j+1);
             dfs(grid , i , j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
         n= grid.size();
          m = grid[0].size();
         int count =0;
          for(int i=0; i<n ; i++)
          {
             for(int j=0; j<m ; j++)
             {
                 if(grid[i][j]=='1')
                 {
                     dfs(grid ,i , j);
                      count++;
                 }
             }
          }
          return count ;
    }
};