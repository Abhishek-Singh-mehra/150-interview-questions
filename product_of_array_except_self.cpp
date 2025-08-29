/*Given an integer array nums, 
return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer
You must write an algorithm that runs in O(n) time and without using the division operation.*/ 
 /* approach 1
  the intution is simple  that first get the totoal product  if thier is any number containg 0 the n
  count number of zero 
   then fill the number if  number of zero is greater than 1  all the number be zero  and rest number 
    divided by  the number at idx.*/  
    /* time complexity 0(n).
     space complexity 0(1).*/
    class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int product = 1; 
         int countzero= 0;
          vector<int>ans(nums.size());
         for(int i=0 ; i<nums.size() ; i++) 
         {if(nums[i]!=0)
         {
              product = product *nums[i]; 
         } 
         else 
          {
            countzero++;
          }
         }

         for(int i=0 ;i<nums.size() ; i++)
         { 
            if(countzero >1)
            {
              ans[i] = 0;
            }
            else if(countzero==1)
            {
                  ans[i] = (nums[i]== 0)?  product: 0;
            }
             else 
             {
                 ans[i] = product /nums[i];
             }
         }  
          return ans;
    }
};