/*Given a sorted array of distinct integers and a target value, 
return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.*/  
/****************************************************** approach 1 ******************************** */ 
 /* we will use the binary searc halgorithm as if we find  the mid == target then return the mid index other wise normal inrement of i or j 
   at last if we are unable to find  it return the i indx.*/
    /*  time complexity O(log n)
     space complexity O(1)
      leetcode link = https://leetcode.com/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-interview-150*/

      class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
           int i=0 ;
           int j = nums.size()-1;
           int mid = 0;

         while (i<=j)
         {
              mid = (i+j)/2;
               if(nums[mid] == target )
               {
                return mid;
               }
              else  if( nums[mid]<target)
              {
                i = mid+1;
              }
              else if(nums[mid]>target)
              {
                j=mid -1;
              }
         }
          return i;
    }
};