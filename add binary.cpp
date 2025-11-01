/*Given two binary strings a and b, return their sum as a binary string.

 */ 
 /* the intution is that we will use the same methord that we are using  to add two numbers 
  and make sure of the carry .*/ 
   /* time complexity O(max(a,b))
      space complexity O(max(a,b))
       leetcode link =https://leetcode.com/problems/add-binary/?envType=study-plan-v2&envId=top-interview-150 */ 

       class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            
            res = char(sum % 2 + '0') + res; // append result bit
            carry = sum / 2; // update carry
        }

        return res;
    }
};
