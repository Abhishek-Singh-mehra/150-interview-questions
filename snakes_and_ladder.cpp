/*ou are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board 
(i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.

Note that you only take a snake or ladder at most once per dice roll. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of dice rolls required to reach the square n2. If it is not possible to reach the square, return -1.*/  


 /*************************************************** approach 1 **************************************** */
  /* always remember if they ask for the minimum thing their is chance of using the dfs bfs .
    the intution is that  we will travel the board wit hte possible chances of  adding at 1 ,2 , 3,4,5,6 to the dice mans move forward .
     we will use the bfs simple and to move forward  and when every tir is  the ladder we will get th coordinates of that and push it toqueue..  the unique and check  if they are 
     in  the last element return the steps. */


     /*time complexity O(n^2)
       space comppleixty O(n^2).
       leetcode link=  https://leetcode.com/problems/snakes-and-ladders/?envType=study-plan-v2&envId=top-interview-150 
        youtube video = https://www.youtube.com/watch?v=26IT3FYm5h8*/
       
       
       
       class Solution {
public:
      int n; 
      pair<int, int> getCoord(int s) {
        int row = n-1-(s-1)/n;
        
        int col = (s-1)%n;
        
        if((n%2==1 && row%2==1)||(n%2==0 && row%2==0))
            col = n-1-col;
        
        return make_pair(row, col);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        
        int steps = 0;
        queue<int> que;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n-1][0] = true;
        
        que.push(1);
        vector<bool> seen(n*n+1,false);
        
        
        while(!que.empty()) {
            
            int N = que.size();
            while(N--) {
            
                int x = que.front();
                que.pop();

                if(x == n*n)
                    return steps;

                for(int k = 1; k<=6; k++) {
                    if(x+k > n*n)
                        break;

                    pair<int, int> coord = getCoord(x+k);
                    int r = coord.first;
                    int c = coord.second;
                    if(visited[r][c] == true)
                        continue;

                    visited[r][c] = true;
                    if(board[r][c] == -1)
                        que.push(k+x);
                    else {
                        que.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};
