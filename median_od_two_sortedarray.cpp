/*Given two sorted arrays nums1 and nums2 of size m and n respectively,
 return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).*/ 
 
/* ********************************  approach 1 *************************************/
 /* the intution is that we will merge the two sotred array and then find the median of the merged array.*/
 /* time complexity O(n+m)
    space complexity O(n+m)
    leetcdoe link =https://leetcode.com/problems/median-of-two-sorted-arrays/?envType=study-plan-v2&envId=top-interview-150 */

    class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
         int m = nums2.size(); 
         vector<int>merged;
         int i=0; int j=0;
          while( i<n && j<m)
          {
             if( nums1[i]<=nums2[j])
             {
                 merged.push_back(nums1[i]);
                  i++;
             }
               else 
               {
                 merged.push_back(nums2[j]);
                 j++;
               }
          } 
           while(i<n) 
           {
            merged.push_back(nums1[i]);
           i++;
           }

           while(j<m) 
           {
            merged.push_back(nums2[j]);
           j++;
           }
            

            int k= merged.size();
            if(k%2==0)
            {
                return ( merged[k/2 -1] +merged[k/2])/2.0;
            }
           else 
           {
              return (merged[k/2]);
           }
    }
};
