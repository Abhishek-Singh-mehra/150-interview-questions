/*A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.*/


/* ********************************************* approach 1********************************************/ 
 /* the intution is that we will  get all the possible change and check if it is present in the bank if it isin the bank then we will move 
 forward and increment the steps if we reach endgene then return the minimum steps  if not then we have to undo the  changes to get the other 
 changes as their  are  4 changes we can do A C G T  means we will use the  recurssion and the backtracking concepts to recurssion we use the 
  dfs with the visited array  if we have seen that earlier mutaiton or not .*/ 
   /* time complexity O(N)
     space complexity O(N) 
      leetcode link= https://leetcode.com/problems/minimum-genetic-mutation/?envType=study-plan-v2&envId=top-interview-150*/ 

      class Solution {
public:
    int minSteps = INT_MAX;

    void dfs(string current, string endGene, unordered_set<string>& bankSet, unordered_set<string>& visited, int steps) {
        if (current == endGene) {
            minSteps = min(minSteps, steps);
            return;
        }

        for (int i = 0; i < current.size(); ++i) {
            char original = current[i];
            for (char c : {'A', 'C', 'G', 'T'}) {
                if (c == original) continue;

                current[i] = c;
                if (bankSet.count(current) && !visited.count(current)) {
                    visited.insert(current);
                    dfs(current, endGene, bankSet, visited, steps + 1);
                    visited.erase(current); // backtrack
                }
            }
            current[i] = original; // restore
        }
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end()); //to get in O(1)for searching.
        if (!bankSet.count(endGene)) return -1;

        unordered_set<string> visited;
        dfs(startGene, endGene, bankSet, visited, 0);

        return minSteps == INT_MAX ? -1 : minSteps;
    }
};
