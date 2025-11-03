/*Given a non-empty array of integers nums, every element appears twice except for one.
 Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.*/ 

/******************************approach 1 **************************************** */
 /* the intution is simple we will use the umordered-map to stroe the numberand its freq then we will search in the  mp and fins the number
 of freq of 1  then return number*/
 /* time complexity O(n)
     space complexity O(1)*/

     class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int ,int >mp;
        for(int i:nums)
        {
             mp[i]++;
        }
         for( auto &num :mp)
         {
             if(num.second==1) return num.first;
         } 
          return 0;
    }

}; 

/**************************************** approach 2 ****************************** */
/* the intution is that we know  that if we do the xor operation between two number that a re same they cancel each out we can use this 
 approach to cancel out and in the last we gat the number which is present at frq of 1. */
 /* time complexity O(n)
    space complexity O(1)
    leetcode link =https://leetcode.com/problems/single-number/description/?envType=study-plan-v2&envId=top-interview-150*/
   
 class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int res = 0;
          for( int &i: nums)
          {
             res = i^res;
          }
           return res ;
    }
};