## Cycle detection in an undirected graph:-

### by using Breath First Search(bfs):
the logic is simple as in the bfs traversal we traverse the graph level wise.
so , in this method we store the parent node with the ele node and when the node is visited and the parent node is not equal to ele node that means the  
some other is already visted that node at the same level which means there is a cycle in the graph.

```cpp
class Solution {
  public:
  
    bool check(unordered_map<int , vector<int>> &adj , vector<int> & vis , int node){
        vis[node] = 1;
        
        queue<pair<int , int>> q;
        q.push({node , -1});
        
        while(!q.empty()){
            int ele = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(int i : adj[ele]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push({i , ele});
                    
                }
                else if(parent != i){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int , vector<int>> adj;
        vector<int> visited(V , 0);
        for(auto ele : edges){
            int u = ele[0];
            int v = ele[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i ; i<V ; i++){
            if(!visited[i]){
                if(check(adj, visited , i)) return true;
            }
        }
        
        return false;
    }
};
```

### by using Depth First Search(dfs):

```cpp
class Solution {
  public:
  
    bool dfs(unordered_map<int , vector<int>> &adj , vector<int> & vis , int node , int parent){
        vis[node] = 1;
        for(int ele : adj[node]){
            if(!vis[ele]){
                vis[ele] = 1;
                if(dfs(adj , vis , ele , node)) return true;
            }
            else if(parent != ele){
                return true;
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int , vector<int>> adj;
        vector<int> visited(V , 0);
        for(auto ele : edges){
            int u = ele[0];
            int v = ele[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i ; i<V ; i++){
            if(!visited[i]){
                if(dfs(adj, visited , i , -1)) return true;
            }
        }
        
        return false;
    }
};

```


