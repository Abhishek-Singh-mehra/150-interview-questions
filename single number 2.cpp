/*Given an integer array nums where every element appears three times except for one, which appears exactly once.
 Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.*/ 

/************************* approach 1 ********************** */
/* the intution is simple we  will use  the map and store the freq of the each number and then  get the number whose frq is one.*/
/* time complexity O(n)
   space complexity O(1)*/

   class Solution {
public:
    int singleNumber(vector<int>& nums) { 
        int n= nums.size();
        unordered_map<int ,int>mp;
        for(int num:nums){
             mp[num]++;
        }
         for(auto num:mp)
         {
             if(num.second==1) return num.first;
         }
         return 0;
    }
}; 


/* ********************************* approach 2 *****************************/
/* the intution is that we will chack the ach bit of every element then we will count the number of set bit in the cureent bit  if 
 its  the multiple of the 3 add it to the ans other wise not */
 /* time complexity O(n)
    space complexity O(1)
     leetcode link = https://leetcode.com/problems/single-number-ii/description/?envType=study-plan-v2&envId=top-interview-150*/


    class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;

    for (int i = 0; i < 32; ++i) {
      int sum = 0;
      for (const int num : nums)
        sum += num >> i & 1;
      sum %= 3;
      ans |= sum << i;
    }

    return ans;
  }
};