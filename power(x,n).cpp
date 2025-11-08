/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).*/

/************************************* approach 1 *********************************** */
 /* the simple intution is  that we will multiple the number  x times. to  do that we will use  the recurssive call .*/
 /* time complexity O(x)
    space complexity O(1).*/

    class Solution {
public: 
    int num  ; 
     double power (double number , long long  i , double x )
     {
         if (i == num)return number ;
          return power(number *x , i+1 , x );
     }
    double myPow(double x, int n) {
         num = abs(n);
        if(n>0) return power(x , 1 ,x);
         else if(n==0) return 1.000;
          else return  1/power(x,1 ,x);
    }
}; 


/****************************** approach 2 *********************************** */
 /* the  thing is that we can  use the bit manuplation concepts  as if we represent the value of x in the binary representation we can 
 get it is even or not by  the first bit .  we  will multiple the power of x to that bit have the one */
  /* time complexity O(log(n))
    space complexity O(1)
     leetcode link = https://leetcode.com/problems/powx-n/description/?envType=study-plan-v2&envId=top-interview-150*/ 

     class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)  x = 1/x; 
        long num = labs(n); //absolute value.
         double pow =1 ;
          while(num)
          {
             if((num&1)!=0){
                 pow *=x;
             } 
             x*=x;
             num>>=1; //divide by 2.
          } 
          return  pow;
    }
};