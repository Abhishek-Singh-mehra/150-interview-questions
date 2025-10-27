/*Given an array of integers nums sorted in non-decreasing order,
 find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
 */  


 /**********************************approach 1 ************************/
 /* the approach is that we use the binary search  to get the mid if we get the mid  equal  to the target then we can move it  to the left and the right till we will the 
   number equal to the target .*/ 

   /* time complexity O(log(n)+k)
      space complexity O(1);
    leetcode link = https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150 
    */

    class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> position(2, -1);
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                int i = mid;
                while (i > 0 && nums[i - 1] == target) {
                    i--;
                }
                position[0] = i;

                int j = mid;
                while (j < nums.size() - 1 && nums[j + 1] == target) {
                    j++;
                }
                position[1] = j;

                return position;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return position;
    }
};
