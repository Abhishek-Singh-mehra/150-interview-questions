/*There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station.
 You begin the journey with an empty tank at one of the gas stations.
Given two integer arrays gas and cost, return the starting gas station's index 
if you can travel around the circuit once in the clockwise direction,
 otherwise return -1. If there exists a solution, it is guaranteed to be unique.*/
  /* approach 1 . 
   the intution  of this approach is that  we traverasl though the gas station 
   and pick   one station at a time if the tank get to 0 or less then their is 
    no chance i can be their again s oi change the  stating point of not 
     then i will move further. */ 
      /* time complexity 0(n).
       space complexity 0(1).*/
     class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumofgas =0;
        int sumofcost =0;
         for(int i=0 ; i<gas.size() ; i++)
         {
             sumofgas += gas[i];
             sumofcost += cost[i];
         }
          if( sumofgas<sumofcost)return -1;

           int total = 0, tank = 0, start = 0;
    for (int i = 0; i < gas.size(); ++i) {
        int gain = gas[i] - cost[i];
        total += gain;
        tank += gain;
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    return total >= 0 ? start : -1;
    }
};