/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.*/ 
 
/* ****************************************** approach 1 **********************************/
 /* the intution is that we  will place the first queen then we will put the second on eat a place where it didnt bicect the other queen, for this wew ill uset he 
  another vector of n*n with false and mark true where the queen moves by this we will place all the queen.  we will move in the row as if we find the right spot inthe row 
   their is no o other place in the smae row we can put the other queen.*/ 
   /* time complexity O(N!)
    space complexity O(n*n)
     leetcode link = https://leetcode.com/problems/n-queens-ii/description/?envType=study-plan-v2&envId=top-interview-150*/ 
     class Solution {
public:
 int cnt;  
bool issafe(vector<vector<bool>>&visited  ,int row ,int col , int n)
{
     for(int i=0 ; i<row ; i++)
     {
         if(visited[i][col])return false;
     } 
     for(int i= row-1  ,j= col-1  ;i>=0&& j>=0 ; i-- ,j--)
     {
        if(visited[i][j]) return false;
     } 
      for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (visited[i][j]) return false;
        }
         return true;
}
    void backtrack(vector<vector<bool>>&visited , int n , int row  )
     {
         if(row ==n)
         {
            cnt++; // base case .
            return ;
         } 
         for(int col = 0 ; col<n ; col++)
         {
             if(issafe(visited , row , col ,n))
             {
                visited[row][col] = true ;
                backtrack(visited ,n ,row+1); // move to next row .
                visited[row][col]= false;  //undo the queen.
             }
         }
     }
    int totalNQueens(int n) {
        cnt =0;
        if(n ==1) return 1;
        if(n==2 || n==3 ) return 0;
        vector<vector<bool>>visited(n ,vector<bool>(n,false)); // vector with false .
        backtrack(visited , n , 0);
        return cnt;
    }
};