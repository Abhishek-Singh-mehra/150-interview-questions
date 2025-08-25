/*Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.*/
 /* approach 1 */
/* intution  is simple first  reverse the array .
 then reverse the array starting an till the  size  give n. 
 then reverse the reset array  from k size to the end . */
  /* time complexity  0(n).
   space complexity  0(1).*/
 class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size(); 
         k = k%size ;
         if(k ==0 ) return ;
         reverse(nums.begin() , nums.end());
          reverse(nums.begin() , nums.begin()+k);
          reverse(nums.begin()+k  ,  nums.end());
    }
};