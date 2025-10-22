/*Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally,
 the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i],
 nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.*/

 /********************************** approach 1 ******************************** */
  /* the intution is that we will put the  nums twice in the another array to remove the circular part then we will apply the kadanes
   algo with the check  case of size of subarray not to exceeded the  original size. */
    /* time complexity O(n^2)
      space complexity O(2n)*/
       
      class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> array(2 * n);
        for (int i = 0; i < n; ++i) {
            array[i] = nums[i];
            array[i + n] = nums[i];
        }

        int maxSum = nums[0];
        for (int start = 0; start < n; ++start) {
            int currSum = 0;
            for (int len = 0; len < n; ++len) {
                currSum += array[start + len];
                maxSum = max(maxSum, currSum);
            }
        }

        return maxSum;
    }
};  
 
/************************* approach 2 ****************************************** */
 /* to use the kadans algothim as get the  minsum adn the max sum then get teh maximum from the maxsum adn the totalsum - minsum.*/
  /* time complexity O(n)
    space compleizty O(1)
     leetcode  link =  https://leetcode.com/problems/maximum-sum-circular-subarray/description/?envType=study-plan-v2&envId=top-interview-150*/

     class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) { 
         // kadanes algo.
        int totalsum =0;
         int maxsum = nums[0] ,currmax = 0 ;
         int minsum = nums[0] ,  currmin = 0;
          for( int num :nums)
          {
             totalsum +=num;
              currmax = max(num  , currmax +num);
              maxsum = max(maxsum ,currmax);

               currmin = min(num  , currmin+num);
               minsum = min(minsum ,currmin);
          } 
           if(maxsum <0) return maxsum;
           return max(maxsum ,  totalsum -minsum);
    }
};