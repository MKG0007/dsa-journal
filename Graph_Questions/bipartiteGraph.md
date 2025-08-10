## bipartite Graph:-
it is the graph on which we try to color using two colors and able to color in such  a way that  adjacent node does not have a same color.
all linear graph are bipartite and the graph that have even cycle is also a bipartite graph.


### by using depth first search:-
```cpp

class Solution {
public:

    bool dfs(vector<vector<int>>& graph , vector<int> &color , int node , int clor){
        color[node] = clor;

        for(int i : graph[node]){
            if(color[i]  == -1){
                int g = -1;
                if(dfs(graph , color , i , !clor)==false) return false;
            }
            else if(color[node] == color[i]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int> color(v , -1);
        for(int i = 0 ; i<v ; i++){
            if(color[i] == -1){
                if(dfs(graph , color , i , 1) == false) return false;
            }
        }

        return true;

        
    }
};

```

### by using breath first search:-
```cpp

class Solution {
  public:
  bool bfs(unordered_map<int , vector<int>> &adj, vector<int> &vis , int node){
      
      vis[node] = 0;
      
      queue<int> q;
      q.push(node);
      
      while(!q.empty()){
          int i = q.front();
          q.pop();
          
          for(int ele : adj[i]){
              if(vis[ele] == -1){
                  
                  vis[ele] = 1 - vis[i];
                  q.push(ele);
              }
              else if(vis[ele] == vis[i]){
                  return false;
              }
          }
      }
      return true;
  }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        unordered_map<int , vector<int>> adj;
        
        for(auto ele : edges){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        vector<int> vis(V , -1);
        
        for(int i = 0 ; i<V ; i++){
            if(vis[i] == -1){
                if(bfs(adj , vis , i) == false) return false;
            }
        }
        
        
        return true;
    }
};

```
