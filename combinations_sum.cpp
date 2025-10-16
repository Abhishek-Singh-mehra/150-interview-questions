/*Given an array of distinct integers candidates and a target integer target,
 return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times.
 Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 */

 /******************************** approach1 ************************************ */ 
  /* the intution is  simple we use  the structure of the permutation but whene ever the nums[i] <= target its a valid candidate to
   gat to the  permutation number so  to add it we will subtract from the target then check for the new target.*/ 
    /* time complexity O(n)
     space coomplexity O(n)
     leetcode link = https://leetcode.com/problems/combination-sum/?envType=study-plan-v2&envId=top-interview-150*/ 

     class Solution {
public:
 void backtrack( vector<int>&candidates , vector<int>&current , int indx , int target  , vector<vector<int>>&res)
 {
     if(target ==0)
     {
         res.push_back(current);
         return ;
     }
     for(int i=indx  ; i< candidates.size()  ; i++)
     {
         if( candidates[i]<=target)
         {
             current.push_back(candidates[i]);
             backtrack(candidates  , current  ,i ,  target-candidates[i] , res);
             current.pop_back();
         }
     }
 }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res ;
         vector<int>current ;
         backtrack( candidates  , current  ,0 ,  target , res);
 return res ;
    }
};