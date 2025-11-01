/*Reverse bits of a given 32 bits signed integer.*/ 
 /* the intution is that we sue the three steps first make the result in  wit hte 
  zero then do the left shift of the res  now get  the  last bit and add it to the res
   num now the last step is that right shift the number to mirror */
 /*time complexity O(1)
   space complexity O(1)*/
   class Solution {
public:
    int reverseBits(int n) { 
         int res =0;
        for(int i=0 ; i<32 ; i++)
        {
              
             int lastbit = n&1;  // get the last bit .
             res = res<<1; // now left shift res
              res = res|lastbit; //  add to the res.
              n =n>>1; // right shift to the num.
        }
        return res;
    }
};