/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.*/
 
 
/************************************* approach1***********************************  */ 
 /* the intution is that while travlling the node or the graph we will get into the
  infinite loop or if we  find the cycle then their is no chances that we can schedule the courses 
  so we will find  the cycle is it retur the true menas theiris no way we will return  the false ,other wise we will return true. */ 

  /* time complexity O(n+e)
     space compleixty (n).*/ 
      
     class Solution {
public: 
bool  iscycledfs( int  i,  unordered_map<int , vector<int>>adj ,  vector<bool>&visited , vector<bool>& recurrsion)
 {
     visited[i]= true ;
      recurrsion[i] = true ;
      for(int &v:adj[i])
      {
         if(visited[v]==false  && iscycledfs(v, adj , visited , recurrsion) ) 
         {
             return  true ;
         } 
         else if( visited[v]== true &&  recurrsion[v]== true )
         {
            return true ;
         }
      }  
      recurrsion[i]= false ;
      return false ;

      
 }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         unordered_map<int , vector<int>>adj;// adjency list .
         for(vector<int>&vec:prerequisites)
         {
             int u = vec[1] ; 
             int v = vec[0];
              adj[u].push_back(v);
         }  
         vector<bool>visited(numCourses, false );
          vector<bool>recurrsion(numCourses, false ); 
           for(int i=0 ; i<numCourses ; i++)
           {
               if(!visited[i]&& iscycledfs(i, adj , visited , recurrsion))
               {
                 return false ;
               } 
               
           } 
           return true ;

    }
};



 /*********************************** approach 2  ********************************* */ 
  /* the intution is  simple we will use the kans algortihm menas to get the indegree of the every node . */ 
   
  /* time complexity O(V+E) vertices and edges.
     space complexity O(V+E)
     leetcode link = https://leetcode.com/problems/course-schedule/description/?envType=study-plan-v2&envId=top-interview-150 */ 

     class Solution {
public: 
 bool khansalgorithm( unordered_map<int , vector<int>>adj ,  vector<int>&indegree , vector<int>&result)
 {
    queue<int>que; 
    int curr ;
    for(int i =0 ; i<indegree.size() ; i++)
    {
         if(indegree[i]==0)
         {
            que.push(i);
         }
    }
     // bfs .
      while(!que.empty())
      {
          curr = que.front(); 
           result .push_back(curr);
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
       return  true ;
 }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //khans algorithm.
         unordered_map<int , vector<int>>adj;
          for(vector<int>&vec:prerequisites)
          {
             int u = vec[1];
              int v = vec[0];
            adj[u].push_back(v);
          } 
           vector<int>indegree(numCourses , 0); 
            vector<int >result ;
            for(int u =0 ; u<numCourses ; u++)
            {
                 for(int &v :adj[u])
                 {
                     indegree[v]++;
                 }
            } 
            khansalgorithm(adj , indegree , result);
            
             if (result .size() == numCourses) {
                return  true  ;
            } 
            else 
            {
              return false ;  
            }
             
    }
};