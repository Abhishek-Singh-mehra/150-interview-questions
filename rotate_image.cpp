/*You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.
 */
/* *************************************approach 1 ********************************************/
/* the approach is simple first transpose the matrix the wwap the columns with each other. */
/*  time complexity 0(n^2)
 space complexity 0(n^2).*/
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        vector<vector<int>> dup(matrix.size(), vector<int>(matrix.size()));
        // replace rows with  rows means transpose .
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                dup[j][i] = matrix[i][j];
            }
        }
        //   now swap the columns from left to right .
        for (int i = 0; i < matrix.size(); ++i)
        {
            int left = 0, right = matrix.size() - 1;
            while (left < right)
            {
                swap(dup[i][left], dup[i][right]);
                ++left;
                --right;
            }
        }
        matrix = dup;
    }
};
/******************approach 2 ************************* */
/* follow up of  the above approach not using the extra space .*/
/* time complexity 0(n^2)
 spcaee complexity 0(1).*/
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Step 2: Reverse each row
        for (int i = 0; i < n; ++i)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

/* ***************************** approach 3 *****************/
/* in this approach we just  place the eac hidx to its  rotated position directly.*/
/* time complexity 0(n^2).
 space complexity 0(1).*/
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dup(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dup[j][n - 1 - i] = matrix[i][j];
            }
        }
        matrix = dup;
    }
};