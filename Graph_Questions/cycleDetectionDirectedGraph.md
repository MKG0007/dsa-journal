
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

### Detect the Cycle in the graph by Kahn's algorithem:-
TopoSort
as the topoSort only applicable on the directed acyclic graph if we tried to find the topoSort of any cyclic graph  
then it returns the incomplete traversal of the graph that shows that graph has a cycle.

```cpp
class Solution {
  public:
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int , vector<int>> adj;
        
        vector<int> in(V , 0);
        for(auto ele : edges){
            adj[ele[0]].push_back(ele[1]);
            in[ele[1]]++;
        }
        
        
        queue<int> q;
        
        for(int i = 0 ; i<V ; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        
        
        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int ele : adj[node]){
                if(in[ele] != 0){
                    in[ele]--;
                    if(in[ele] == 0) q.push(ele);
                }
            }
        }
        
        if(ans.size() < V) return true;
        
        return false;
        
    }
};

```
