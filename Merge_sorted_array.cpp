/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function,
 but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n,
  where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored.
   nums2 has a length of n.*/
// approach1
// add the  number of num2 to the num1 array from the nsize  onward.

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
       
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }
};
 // time complexity will be the 0(nlog n) and hte 
 // space complexity will be 0(n).

 // approach 2 .
 /* the intution is like  rhis we will make a poitner at k of size m+n-1 and the i nad j point to the last index of num1 and num2
      then we will compare then with each otherand ut the greatr to the k place and decrement   at last thecase where  n is greater then the m so we will
        traverse the lopp  of j then put it in the k place . */
        void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{ 
    int i=m-1 ;
    int j=n-1;
    int k =(m+n)-1;
    while(i>=0 && j>=0)
    {
        if(nums1[i]>nums2[j])
        {
            nums1[k]=nums1[i];
            k--;
            i--;
        }
        else
        {
            nums1[k]= nums2[j];
            k--;
            j--;
        }
    }
    while(j >= 0){
    nums1[k--] = nums2[j--];
}
} 
 // time complexity will bee 0(n).
 // space comlexity will be 0(1).