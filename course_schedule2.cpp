/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
 You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers,
 return any of them. If it is impossible to finish all courses, return an empty array.
 */ 
 
  /************************************** approach 1 ***************************************** */ 
   /* the intution  is that we will use the kahns algorithm and we will return the  vector whic will give the topological sorting.*/ 
    /* time complexity O(V+E)
       space complexity O(V+E)
       leetcode link = https://leetcode.com/problems/course-schedule-ii/?envType=study-plan-v2&envId=top-interview-150 */ 
         

    class Solution {
public: 
void kahnsalgo(unordered_map<int  , vector<int>>adj , vector<int>&indegree , vector<int>&ans)
{
    
    queue<int>que;
    for(int i=0 ; i<indegree.size() ; i++)
    {
         if(indegree[i]==0)
         {
             // push to que .
              que.push(i);
         }

    }
    //bfs .
    while(!que.empty())
    {
         int curr = que.front();
         ans.push_back(curr);
         que.pop();
         for(int &v:adj[curr])
         {
             indegree[v]--;
             if(indegree[v]==0)
             {
                que.push(v);
             }
         }
    }
}
    vector<int> findOrder(int numscourses, vector<vector<int>>& prerequisites) {
         
         vector<int>ans;
         unordered_map<int , vector<int>>adj;
         //adj list . 
           for(vector<int>&vec:prerequisites)
           {
             int u = vec[1];
              int v = vec[0];
             adj[u].push_back(v);
           } 
         //indegree vector. 
         vector<int>indegree(numscourses , 0);
         for(int u =0 ; u<numscourses ; u++)
         {
             for(int &v:adj[u])
             {
                 indegree[v]++;
             }
         }
         //kahns algorithm function. 
            kahnsalgo(adj , indegree , ans);  
          
         /// condition return ans 
          vector<int>other;
          if(ans.size()<numscourses)return other;
          return ans;
    }
};