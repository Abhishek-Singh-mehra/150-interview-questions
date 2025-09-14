/*Given an m x n integer matrix matrix, if an element is 0,
 set its entire row and column to 0's.
You must do it in place.*/

/******************************approach1 **************** */ 
 /* the idea is that we will make the  vector of rows and colmn 
  if the  and fill of the row is 0 the ntrue ,same 
  with the colmn ,then travel in the matric and if we get the row or column true 
  we make the idx as 0 .*/
  /* time complexity 0(n*m)
  space complexity 0(m+n).
   leetcode link =https://leetcode.com/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150*/
   class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
         int m = matrix[0] . size();
           vector<bool>row(n  ,false); //row vector.
           vector<bool>cols(m , false);// column vector.

            for(int i =0 ; i< n ; i++) // fill the row and colif zero encounterto true.
            {
                 for(int j =0   ; j  <m  ;j++)
                 {
                     if(matrix[i][j] ==0)
                     {
                         row[i] = true ;
                          cols[j] = true;
                     }
                 }
            } 
             for(int i=0 ;  i<n ; i++) 
             {
                 for(int j =0 ; j<m  ;j++)
                 { 
                     if( row[i]== true  ||cols[j]==true ) // if oe of the row or col is true entire  row or col will be 0.
                     {
                        matrix[i][j] = 0;
                     }
                 }
             }

    }
};