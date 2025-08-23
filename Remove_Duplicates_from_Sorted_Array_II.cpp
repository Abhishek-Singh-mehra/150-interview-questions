/*Given an integer array nums sorted in non-decreasing order,
 remove some duplicates in-place such that each unique element appears at most twice. 
The relative order of the elements should be kept the same.
Since it is impossible to change the length of the array in some languages,
 you must instead have the result be placed in the first part of the array nums. More formally,
  if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. 
It does not matter what you leave beyond the first k elements.
Return k after placing the final result in the first k slots of nums.
Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.*/ 
 /*approach 1 
    its a follow up question  ofthe remove the duplicate the nmber from the  array we follow that question only 
     ar in  that quetion we track the  j pointer with the conditio  if(ivalue !=i-1value ) in this we will do same but wit hte pointer j - 2 smaller
      than that this will make sure  that hte number  and the smaller number  hafe its duplicates and now its more than that .
       */ 
    /*time complexity   0(n).
     space  complexity 0(1)*/
      class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;  // Pointer for placing allowed elements
        for (int j = 0; j < nums.size(); ++j) {
            if (i < 2 || nums[j] != nums[i - 2]) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};