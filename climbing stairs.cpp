/*You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?*/ 


/* ********************************* approach 1 **************************/
/* the intution is that we will use  the recurssion approach get all the possible 
ways to get at the top by skipping  the one ladder or the 2 ladder */
/* time complexity (2^n)
   space complexity O(n)*/

   class Solution {
public:
 void recc(int n  , int i , int  &ways)
 {
     if( i==n) 
     {
      ways++;
     return ;
     }

      else if( i>n)return;
       recc(n , i+1 , ways);
        recc(n , i+2 , ways);
 }
    int climbStairs(int n) {
       int  ways =0;
       recc(n , 0 , ways);
       return ways; 
    }
};



/* ******************************** approach 2 **************************/
/* we can use  the fibonnacci approach no f ways = (n+1) +(n+2)......*/ 
  

/* time complexity O(n)
 space comlexity O(1)
  leetcode   link  =https://leetcode.com/problems/climbing-stairs/description/?envType=study-plan-v2&envId=top-interview-150 */ 

  class Solution {
public:
    int climbStairs(int n) {
         if(n<=2)  return  n;
          int prev1 = 1 ;
           int prev2 = 2 ;
            for(int i=3 ; i<=n   ; i++)
            {
                 int curr = prev1 + prev2 ;
                   prev1 =  prev2 ;
                    prev2  = curr ;
            }
            return prev2 ;
    }
};