/*Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 */
/************************************ approach 1*********************************/
/* brute force approach .
  we  make the 3 loop 1 for chehcking in the row 2 for the column and last for the column check of size 3*3.*/
/*time complexity 0(n^2).
  space complexity 0(1). as the size of the set is from 0 to 9onlt  so constant .*/
class Solution
{
public:
    bool checkthegrid(vector<vector<char>> &board, int rs, int re, int cs, int ce)
    {
        unordered_set<char> check;
        for (int i = rs; i <= re; i++)
        {
            for (int j = cs; j <= ce; j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (check.find(board[i][j]) != check.end())
                    return false;
                check.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {

        // for the row.
        for (int i = 0; i < 9; i++)
        {
            unordered_set<char> row;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (row.find(board[i][j]) != row.end())
                    return false;
                row.insert(board[i][j]);
            }
        }
        // now for the column .
        for (int i = 0; i < 9; i++)
        {
            unordered_set<char> col;
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.')
                    continue;
                if (col.find(board[j][i]) != col.end())
                    return false;
                col.insert(board[j][i]);
            }
        }

        // now to check  fo the grid of 3*3.
        for (int rs = 0; rs < 9; rs += 3)
        {
            int re = rs + 2;
            for (int cs = 0; cs < 9; cs += 3)
            {
                int ce = cs + 2;
                if (!checkthegrid(board, rs, re, cs, ce))
                    return false;
            }
        }

        return true;
    }
};
/**********************************approach 2 ******************************* */
/* the intution is that to minimize the functions that we use seprately to get into row , col and then grid check.*/
/* time coplexity 0(n^2).
 space complexity 0(1).
  leetcode link = https://leetcode.com/problems/valid-sudoku/submissions/1768389360/?envType=study-plan-v2&envId=top-interview-150*/
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            unordered_set<char> row, col, box;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.' && !row.insert(board[i][j]).second)
                    return false;
                if (board[j][i] != '.' && !col.insert(board[j][i]).second)
                    return false;
                int rowidx = 3 * (i / 3) + j / 3;
                int colidx = 3 * (i % 3) + j % 3;
                if (board[rowidx][colidx] != '.' && !box.insert(board[rowidx][colidx]).second)
                    return false;
            }
        }
        return true;
    }
};
