/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 */

 /****************************************** approach 1 ************************************ */
  /* the intution is simple traverse the whole array and check for the target element in the array.*/ 
  /* time complexity O(n)
     space complexity O(1)*/

     class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        for(int i=0 ; i<n ; i++)
         {
             if( nums[i] == target) return i;
         }
         return -1;
    }
}; 
 
/**************************************** appraoch 2 ******************************* */ 
/* the intution is that we  use  the binary  search and  we draw the graph of th given array to better undersatnd 
    after find the mid if the mid value is greater than the target possibility is that the target lies in the left side and again if the 
    target is greater and smaller than the mid then definately it lies in  between them so we will move the right to the mid and vice versa.*/ 
     
    /* time complexity O(log(n))
       space complexity O(1)
        leetcode link = https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150*/
         
        class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(); 
         int left =0;
          int right = n-1 ;
           while(left<=right)
           {
             int mid=  left+(right-left)/2;
             if(nums[mid]==target)
             {
                 return mid ;
             }
              else if( nums[left]<=nums[mid])
              {
                 if( target>=nums[left] && nums[mid]>target)
                 {
                     right = mid -1 ;
                 }
                 else 
                 {
                      left = mid +1 ;
                 }
              }
              else {
               
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1; 
                } else {
                    right = mid - 1; 
                }
            }
           }
           return -1 ;
    }
};