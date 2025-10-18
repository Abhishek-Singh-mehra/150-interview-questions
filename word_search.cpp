/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells,
 where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.*/

 /****************************** approach1 ************************** */ 
  /* the intution is  that we will traverse in the board and searc hfor the  firat word if matched then its a possible candidate to 
   start the search from that index left right bottom and upward .*/
   /* time complexity O(N*M*4^L)
    space omplexity O(L)
    leetcode link = https://leetcode.com/problems/word-search/description/?envType=study-plan-v2&envId=top-interview-150*/

    class Solution {
public: 
 vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
   bool find(string &word , vector<vector<char>>&board , int i , int j , int idx ,  int n , int m)
   {
    //base case .
     if( idx == word.length())
     { 
        return true ;
     }
      if( i<0 || j<0 || i>=n || j>=m ||  board[i][j]=='$') 
      {
         return false ;
      } 
      if(board[i][j]!=word[idx])
      {
            return false ;
      }
     // i can move to the left right up and down .
      char temp = board[i][j];
      board[i][j] ='$';
      for(auto& dir :directions) // moving to the directions.
      {
         int i_= i+dir[0];
         int j_ = j+dir[1];
          if( find(  word , board , i_ , j_ , idx+1 , n , m))
          {
            return  true ;
          }
      }
        board[i][j] = temp;
         return false ;

   }
    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size();
         int m = board[0].size();
         for(int i=0; i<n ; i++) // iterate in the board.
         {
             for(int j =0 ; j< m ; j++)
             {
                 if( board[i][j]==word[0] && find(word , board , i ,j  ,0 , n , m))
                 { 
                    return true ;
                 }
             }
         } 
          return false ;
    }
};