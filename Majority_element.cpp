/*Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.*/

/*approach 1
 the intution is that  use another array which store the  frequency of the numbers present in the original array then  
  return the number which have the  maximum frequency .
 */
 /* time complexity  0(n)
  space complexity 0(n)*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
         unordered_map<int , int>mp;
         int n = nums.size();
         for(int i=0 ; i<n ; i++)
         {
             mp[nums[i]]++;
         }
          // now traverse in the  map ;
           int res =0;
             for( auto & i : mp)
             {
                 if( i.second >mp[res]) res =i.first;
             }
              return res ;
    }
};
 
/* approach 2 
    the intution is simple  we will chose the element and assume that its the ans  then when ever we counter the number
     in the array we ++ if not we --  at a point if the  count =0 that neams  the number is not  so the next number will be the 
      number at the i  position  and when    count seems like greater than the  size of whole array   number is the ans . */
/*  time complexity 0(n).
 space complexity = 0(1).*/
      class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == candidate) {
                count++;
            } else if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else {
                count--;
            }
        }
        return candidate;
    }
};