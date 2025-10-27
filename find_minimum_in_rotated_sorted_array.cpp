/*Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.*/

/* ************************************** approach 1 ********************************/
 /* the basic approach is that we will  do the linear search in the array then we wil get the min element .*/
 /* time complexity O(n)
    space complexity O(1)*/ 

    class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
         int min = INT_MAX;
          for(int i=0 ; i<n ; i++)
          {
             if(nums[i]<min) min =nums[i];
          } 
          return min;
        }
    };


    /******************************************* approach 2 ****************************************** */
     /*  the intutuion is that we will use the binary searh if the  mid is greater than the right element that menas the  array is rotated and the smallest element lies on the 
      right side of the mid  and just opposite to that .*/
       /* time complexity O(log(n))
           space compexity O(1).
            leetcode link = https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150 */ 

            class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
         int left =0;
         int right = nums.size() -1;
          while(left <right){
              
              int mid = left+(right -left)/2;
               if(nums[mid]>nums[right])
               {
                 left = mid+1;
               } 
               else 
               {
                 right =mid;
               }
          } 
          return nums[left];

    }
};