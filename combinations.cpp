/*Given two integers n and k, 
return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.*/ 
 /* *************************************************approach 1 *************************************************/
  
 /* the intution is that we first generate a simple combination of nunberof size k ans when we backtrackwe will use the 
    chanfe of the number .linke 1 2 3  then 1 2 4 like this .*/
     /* time compleixty O((n/k)*k)
        space complexity O(n)
        leetcode link = https://leetcode.com/problems/combinations/description/?envType=study-plan-v2&envId=top-interview-150*/ 
        class Solution {
public: 
        vector<vector<int>>result ;
         vector<int>current; 
     void backtrack(int start , int n ,  int k)
     {
         if( current.size()==k) // base case .
         {
             result .push_back(current);
             return;
         }
          for(int i= start ; i<=n ; i++)
          {
             current.push_back(i); // push to current generating the new combination.
             backtrack(i+1 , n , k); //use the recursion  to go further 
             current.pop_back(); //backtrack to get back to the number .
          }
     }
    vector<vector<int>> combine(int n, int k) {
        
        backtrack(1 ,n ,k);
         return result ;
    }
};