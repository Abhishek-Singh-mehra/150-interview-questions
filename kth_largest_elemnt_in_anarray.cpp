/*Given an integer array nums and an integer k, 
return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, 
not the kth distinct element.

Can you solve it without sorting?*/

/****************************** approach 1 *******************************/
/* using the sorting technique we sort the array and the nwe will pul out the k element from it */
/* time complexity O(log(n))
   space complexity O(1)*/ 
   class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         int n = nums.size();
        sort(begin(nums) , end(nums));
         return nums[n-k];
    }
};

/***************************** approach 2 ****************************** */ 
/* the intution is  that we should use the proiority  que in the asscending order with the size of k as the number get more than the size 
 we will pop the elemement from the top lastlty we the the k element in the top .*/
 /*  time complexity O(n)
     space complexity O(k)
     leetcode link = https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-interview-150*/ 

     class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int , vector<int> ,   greater<int>>minheap; 
        for(int num :nums)
        {
             minheap.push(num);
             if(minheap.size()>k)minheap.pop();

        } 
        return minheap.top();
    }
};