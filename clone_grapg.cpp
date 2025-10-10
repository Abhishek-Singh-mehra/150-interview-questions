/*Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1,
 the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. 
Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. 
You must return the copy of the given node as a reference to the cloned graph.
*/

/*********************************** approach1 *********************************** */ 
 /* the intution is simple use the concepts and use the map to store the node whic we have clone to check  if we get into the infinite loop /or create it again.*/ 
 /* time compleixty O(N+E)
    space complexity O(n+E).
    leetcode link = https://leetcode.com/problems/clone-graph/description/?envType=study-plan-v2&envId=top-interview-150*/ 
     
    /*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public: 
    unordered_map<Node * ,Node *>visited; // to store theclone node .
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr ; //menas that we are the end 
        if(visited.find(node) != visited.end())
        {
             return visited[node];
        } 
         Node * clone = new Node(node ->val); // creating the clone .
         visited[node] = clone;
         for(Node * neighbor : node ->neighbors) // now traversing the clone neighbors to move further menas dfs or bfs.
         {
            clone ->neighbors.push_back(cloneGraph(neighbor)); 
         }
         return clone;
    }
};