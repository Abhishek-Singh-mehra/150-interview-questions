/*ccording to Wikipedia's article: "The Game of Life, also known simply as Life,
is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0).
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.

Given the current state of the board, update the board to reflect its next state.

Note that you do not need to return anything.

 */
/* *************************** approach 1**************************************/
/* intution is simple traverse the eac hidx and collect the live cell around it and simple
 condition to put in  the duplicate vector .
  time complexity 0(n*m).
   space complexity 0(n*m).
    leetcode link =https://leetcode.com/problems/game-of-life/?envType=study-plan-v2&envId=top-interview-150*/

class Solution
{
public:
    int count(int i, int j, vector<vector<int>> &board)
    {
        int res = 0;
        int rows = board.size(), cols = board[0].size();

        // Directions for 8 neighbors
        vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};

        for (int d = 0; d < 8; ++d)
        {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && board[ni][nj] == 1)
            {
                res++;
            }
        }
        return res;
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>> dup(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                int liveNeighbors = count(i, j, board);
                if (board[i][j] == 1)
                {
                    if (liveNeighbors < 2 || liveNeighbors > 3)
                        dup[i][j] = 0; // Dies
                    else
                        dup[i][j] = 1; // Lives
                }
                else
                {
                    if (liveNeighbors == 3)
                        dup[i][j] = 1; // get to live
                }
            }
        }
        board = dup;
    }
};
