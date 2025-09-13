/*Given an m x n matrix, return all elements of the matrix in spiral order.*/ 
 /*  *********************************approach1***********************/ 
  /* the intution is htat we just travelin the spirial order as we use the 4 pointer and make sure they 
   never   passes each other . first two as top and bottom  to travel to the  down and left and right pointer 
    to travel from left to right  by this we can print the spiral matrix .*/
    /* time complexity 0(n^2)
       space comlexity 0(1).
       leetode link =https://leetcode.com/problems/spiral-matrix/?envType=study-plan-v2&envId=top-interview-150 
       youtube link to understand the problem =https://www.youtube.com/watch?v=73j2ipxR958&t=1388s*/ 
       class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int top = 0;
        int bottom = row - 1;
        int left = 0;
        int right = col - 1;
        while (top <= bottom && left <= right) { 

            for (int i = left; i <= right; i++) {// to travel from left to right .
                ans.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++) { 
                //now t otrave lfrom top to bottom in the right corner .
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom) {
                // now to travel from  right to left in the bottom corner .
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) { 
                // now to travel from bottom to the top inthe left corner .
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};