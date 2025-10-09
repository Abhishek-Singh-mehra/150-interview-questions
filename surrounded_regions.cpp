/*You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 */
/************************************approach1 *********************************** */ 
 /* the intution is that we will traverse the border area and when we encounter the 0 then we will do the dfs to get all the 0 connected to 
  the border  and mark them with special character 's' and then we will again traverse the matrix and  change the 0 with x and s with the 0.*/
 /* time complexity O(n*m)
    space compleixty O(n*m)
    leetcdoe link= https://leetcode.com/problems/surrounded-regions/?envType=study-plan-v2&envId=top-interview-150*/ 
    class Solution {
public: 
int n,m;
    void dfs( vector<vector<char>>& board  , int i , int j)
    {
         if(i<0 ||j<0|| j>=m||  i>=n||  board[i][j]!='O') return; // base condition.
          board[i][j]='s'; 
          dfs(board, i , j+1); // traverse to the up down and right left recurssive .
          dfs(board ,i , j-1);
          dfs(board , i+1 , j);
          dfs(board , i-1 ,j);
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

       
         for(int i=0; i<n ; i++)
         {
             if(board[i][0]=='O') dfs(board ,i , 0);
             if(board[i][m-1]=='O')dfs(board , i ,m-1);
         } 
          for(int j=0;j<m ; j++)
         {
             if(board[0][j]=='O') dfs(board ,0 , j);
             if(board[n-1][j]=='O')dfs(board , n-1 ,j);
         } 
          
         for(int i=0; i<n ; i++)
         {
             for(int j=0 ; j<m ; j++)
             {
                 if( board[i][j]=='O') board[i][j]='X';
                 else if(board[i][j]=='s')board[i][j]='O';
             }
         }
    }
};