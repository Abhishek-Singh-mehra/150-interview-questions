/*Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.*/
  /* link  to the problem = https://leetcode.com/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-interview-150*/
   /* approach 1 .
     thus if wee look inot a small   part of this question  we find that that   water containg at any indx is the min of
     the smallest height to the left and the right  subtract by the  its own height .*/ 
      /* time complexity = 0(n).
       space complexity = 0(n).*/
     class Solution {
public:
    vector<int> leftmaxarray(vector<int> &height, int n) {
        vector<int> ans(n);
        int currMax = height[0];
        ans[0] = currMax;
        for (int i = 1; i < n; i++) {
            currMax = max(currMax, height[i]);
            ans[i] = currMax;
        }
        return ans;
    }

    vector<int> rightmaxarray(vector<int> &height, int n) {
        vector<int> ans(n);
        int currMax = height[n - 1];
        ans[n - 1] = currMax;
        for (int i = n - 2; i >= 0; i--) {
            currMax = max(currMax, height[i]);
            ans[i] = currMax;
        }
        return ans;
    }

    int trap(vector<int>& height) { //  main function .
        int n = height.size();
        vector<int> leftmax = leftmaxarray(height, n);
        vector<int> rightmax = rightmaxarray(height, n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int h = min(leftmax[i], rightmax[i]) - height[i];
            if (h > 0) sum += h;
        }
        return sum;
    }
};
