/*Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially.
 The remaining elements of nums are not important as well as the size of nums.
Return k.*/ 
  
 /*approach1 
    the  approach goes like this    we put the two pointer  i and j  i will move when ever we found that the number at i is equal to the i-1 as
     their is chanes that further their may be duplicate  and if they are not equal  the we  overwrite the number  j  with i which always be at the point,
      where  their is not equal numberthan theprevious number .
     */ 
    /* time comlexity  0(n).
     space complexity 0(1).*/
    class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =1 ;
         int  j = 1;
           while(i<nums.size())
           {
             if( nums[i]== nums[i-1])
             { 
                i++;
             }
              else 
              {
                 nums[j] = nums[i];
                  i++;
                   j++;
              } 
           }
            return j;
    }
};