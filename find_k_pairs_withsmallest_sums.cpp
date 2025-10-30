/*You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.*/  


 /************************************************approach 1 ************************************** */ 
 /*  the intution is that we will get all the pair and their sum and store them in the min heap (priority_queue) then check in the queue if we get eh size more we will pop the 
  front .*/
   /* time complexity O(n.m.logk)
      space complexity O(k)*/

      class Solution {
    public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>res;  
       
        priority_queue<pair<int , pair<int , int>>>pq; 
           
           int n= nums1.size(); 
           int m = nums2.size();

          // form the pair.
           for(int i=0;  i<n ; i++)
           {
             for(int j=0 ; j<m ; j++)
              {
                    int sum = nums1[i] +nums2[j];
                    pq.push({sum ,{nums1[i] , nums2[j]}});
                    if(pq.size()>k)pq.pop();
              }
           }
        while(!pq.empty())
        {
             auto top  =pq.top();
             pq.pop();  
             res.push_back({top.second.first, top.second.second});
        }
        reverse(res.begin(), res.end());
         return res;
    }
}; 

 
/***********************************************approach 2 ******************************************* */ 
/*   we will use the min  heap priority que and the sorting technique for this in this approah as the nums are sorted so we will  this approach .*/
/* time complexity O(klogk)
   space complexity O(k)
    leetcode link = https://leetcode.com/problems/find-k-pairs-with-smallest-sums/?envType=study-plan-v2&envId=top-interview-150*/ 

    class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int n = nums1.size(), m = nums2.size();

        // Min-heap: stores {sum, index in nums1, index in nums2}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;

        // Initialize heap with first k pairs from nums1 and nums2[0]
        for (int i = 0; i < n && i < k; ++i) {
            minHeap.emplace(nums1[i] + nums2[0], i, 0);
        }

        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top(); minHeap.pop();
            res.push_back({nums1[i], nums2[j]});

            // Push next pair in row (i, j+1)
            if (j + 1 < m) {
                minHeap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }

        return res;
    }
};
