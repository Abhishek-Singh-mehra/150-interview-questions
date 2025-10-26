/*A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index.
 If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words,
 an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 */

 /************************** approach 1 ******************** */ 
 /* the intution  is that we will traverse the whole array nums then  check the num
  greater than the greater element till we get if we find new one store its indx and move forward.*/
   /*time complexity O(n)
     space complexity O(1)*/

     class Solution {
public:
    int findPeakElement(vector<int>& nums) {

          int indx =0; 
        int n = nums.size();
         for(int i=0 ; i<n ; i++)
         {
             if( nums[i] >nums[indx]) indx = i;
         } 
          return indx;

    }
}; 
 


/* *********************** approach 2 *********************************/ 
/* the intution is that we will  use the binary search  in the given array as we get teh mid then check for the cindition that if the number art mid is greater than the its 
 exceeding nums[mid+1] then its  valid peak  so their is no need to traverse the right hand side vive verse of its to mov tothe left . */ 
  /* time comlexity O(log(n))
     space complexity O(1)
     leetcode link = https://leetcode.com/problems/find-peak-element/description/?envType=study-plan-v2&envId=top-interview-150*/

     class Solution {
public:
    int findPeakElement(vector<int>& nums) {
          int i=0; 
          int n = nums.size();
           int j= n-1;
            while( i<j)
            {
                 int mid = i+(j-i)/2;
                  if( nums[mid] >nums[mid+1])
                  {
                     j= mid ;
                  } 
                  else 
                  {
                     i= mid +1;
                  }
            } 
            return i;
    }
};

     