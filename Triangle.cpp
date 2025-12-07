/*Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below.
 More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.*/ 

 /*********************************approach 1 **************************** */
 /*As the question mention that we can pick the number or the  next indx number we have choices so we will use recurssion we will get all he possible approach 
 and get  the minimum  sum.*/
 /* time complexity O(2^n)
    space complexity O(h)*/
      
    class Solution {
    public: 
    int solve( int indx , int inneridx,vector<vector<int>>&triangle)
    {
        if(indx == triangle.size()-1) return triangle[indx][inneridx]; // if last indx we get teh n return that value .
        return triangle[indx][inneridx] +min(solve(indx+1 ,inneridx , triangle) ,solve(indx+1 ,inneridx+1 , triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(0,0, triangle);
    }
}; 



/********************************* approach 2 ****************************** */
/*  we wil get the minimum value of every indx which is below them as its sum below which is minimum.
    example  
     2
    3 4
   6 5 7
  4 1 8 3 
  look at the nuber 4 in the third row what iwill be the smallest sum for that  is the below number  of same index and the forward +1 indx 
  in this case 1 is smaller than the4 so we will pick the 1 and addwith the 6 for this part doing all this to above . */ 
  /* time complexity O(n^2)
     space complexity O(1)
      leetcode link  =https://leetcode.com/problems/triangle/?envType=study-plan-v2&envId=top-interview-150 */  

      class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
         for(int i=n-2 ;i>=0 ; i--)
         {
             for(int j= 0 ; j<triangle[i].size() ; j++)
             {
                 triangle[i][j] = triangle[i][j]+min(triangle[i+1][j] ,triangle[i+1][j+1]);
             }
         }
         return triangle[0][0];
    }
};
