
## Cycle Detection in Directed Graph:-
in this case, we can not normal parent node mathod which we used in undirected graph  
because the cycle should only be considered when it forming a loop even with directions.

so, we check the prev path with current path if the path is same then the given graph has a cycle.

```cpp

class Solution {
  public:
  
    bool cycleCheckDfs(unordered_map<int , vector<int>> &adj , vector<int> &vis , vector<int> &path , int node){
        vis[node] = 1;
        path[node] = 1;
        
        for(int ele : adj[node]){
            if(!vis[ele]){
                if(cycleCheckDfs(adj , vis , path , ele)) return true;
            }
            else if(vis[ele] && path[ele]) return true;
            
        }
        
        path[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int , vector<int>> adj;
        vector<int> vis(V , 0);
        vector<int> path(V , 0);
        for(auto ele : edges){
            adj[ele[0]].push_back(ele[1]);
        }
        
        for(int i = 0 ; i<V ; i++){
            if(!vis[i]){
                if(cycleCheckDfs(adj , vis , path , i)) return true;
            }
        }
        return false;
    }
};

```
