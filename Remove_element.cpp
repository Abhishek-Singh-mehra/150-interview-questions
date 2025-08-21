
/*Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
The order of the elements may be changed.
 Then return the number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.*/

 /*approach1  
   the intution si that we will sift all the element to the front which are not equal to the  val.
    time complexity 0(n).
     space complexity 0(1). */ 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) { 
         int j=0;
        for(int i=0 ; i<nums.size() ; )
        {
              if(nums[i]!=val)
              {
                 nums[j] = nums[i];
                j++;
              } 
               i++;
        }
         return  j;
    }
};  
/* approach 2 .
 the intution  is  that we make an array  and push the element in the  array which are not eqaul to the val.
  time complexity 0(n).
   space complexity 0(n)*/

 class Solution {
public:
    int removeElement(vector<int>& nums, int val) { 
         vector<int>dummy;
        for(int i=0 ; i<nums.size() ; )
        {
              if(nums[i]!=val)
              {
                dummy.push_back(nums[i]);
              } 
               i++;
        }
         nums = dummy ;
         return dummy.size() ;
    }
};  