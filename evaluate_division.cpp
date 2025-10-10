/*D


You are given an array of variable pairs equations and an array of real numbers values, 
where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. 
Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.*/
 
 
/********************************** approach 1 *********************** */
 /* the approach is  that we store hte equaction in the adj list example a-->(b,3) menas adivided by b gives 3 linke this,
  and the vice versa b--->(a,1/3), then in the query setion we will travel from source to destination menas query =[{a,c}] so
  ewe will travel from a-->b -->c and multiple the value associate to it .  traversel be like bfs or dfs as it acts like a graph .*/ 
   /*time complexity O(N+E).
    space complexity O(N)
    leetcode link =https://leetcode.com/problems/evaluate-division/description/?envType=study-plan-v2&envId=top-interview-150*/ 

    class Solution {
public:


 void dfs(unordered_map<string  , vector<pair<string , double>>>&adj , string &source  ,string &dst  , unordered_set<string>&visited , double product  ,double &ans )
 {
     

     if( visited.find(source)!= visited.end())
     {
         return ;
     } 
      visited.insert(source);
      if(source == dst )
      {
         ans = product;
          return ;
      } 
       for( auto &p: adj[source])
       {
          string v = p.first ;
          double val = p.second ;
          dfs( adj  , v , dst  , visited , product*val  , ans );
       }
 }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) { 
        int n = equations.size();
        unordered_map<string  , vector<pair<string , double>>>adj; //adj list .
        for(int i =0 ; i< n  ; i++)// input  to the adj list .
        {
             string u = equations[i][0];
             string v = equations[i][1]; 
              double val = values[i];
             adj[u].push_back({v, val});
              adj[v].push_back( {u , 1.0/val});
        }

        vector<double>result ;
        for(auto &query : queries)
        {
              string source  = query[0];
              string dest  = query[1]; 
                double ans =-1.0;
                double product = 1.0;
               
               if(adj.find(source )!= adj.end())
               {
                 unordered_set<string>visited; // calling visited to look as we have traverse itor not .
                 dfs(adj , source , dest , visited  , product  , ans);
               }

               result.push_back(ans );

        }
        return result ;
        
    }
};