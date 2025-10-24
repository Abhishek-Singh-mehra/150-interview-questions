/*ou are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 */ 
 
 /********************************** approach 1 ********************************* */
  /* the intution  is that we will traverse each the index then check if it matches the target .*/
   /* time compleixty O(n^2)
      space complexity O(1)*/

      class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int  n  =matrix.size();
         int m = matrix[0].size();
          for( int i=0 ; i<n ; i++)
          {
             for (int j= 0 ; j<m ; j++)
             {
                 if( matrix[i][j]==target) return true ;
             }
          } 
          return false ;
    }
};  
 
/***************************** approach 2***************************************** */ 
 /* the intution is that as in the question given each row is sorted so if we chack the last indx of the every row if it is greater than the 
 target their is the possible  that answer lies within that range .*/ 
  /* time complexity O(n log(m))
     space complexity O(1)*/

     class Solution {
public:
    bool binarysearch(vector<vector<int>>& matrix, int i, int target, int m) {
        int left = 0;
        int right = m - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[i][mid] == target)
                return true;
            else if (matrix[i][mid] < target)
                left = mid+1;
            else
                right = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int j = m - 1;
        for (int i = 0; i < n; i++) {

            if (matrix[i][j] >= target) {
                // now perform binary search.
                return binarysearch(matrix, i, target, m);
            }
        }
        return false;
    }
}; 
 
/**************************************** appraoch 3 ************************************* */ 
/* we can use the binary search in the whole matrix  as pointing the left ar o adn the right at the last most index then put the binary 
search.*/ 
 /* time compleixty O(log(n))
     pace complexity O(1)
     leetcode link =https://leetcode.com/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-interview-150*/ 
     class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
            
            int  n = matrix[0].size();
            int i= 0; 
           int j= matrix.size() *n-1;
           while(i<= j)
           {
             int mid = i + (j-i)/2;
             if( matrix[mid/n][mid%n]== target)
             {
                return true;
             }
              else if( matrix[mid/n][mid%n] > target)
              {
                j = mid-1;
              } 
              else
              {
                  i = mid +1;
              }
           } 
           return false;
    }
};