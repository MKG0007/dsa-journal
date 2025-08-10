## TopoSort of the Graph:-
if there is a edge between node1 and node1 then the node1 must come before the node2  
for topoSort , graph must be a directed Acyclic graph.


### topoSort by using Depth First Search(dfs):-
```cpp
class Solution {
  public:
  
    void dfs(unordered_map<int , vector<int>> &adj , vector<int> &vis , stack<int> &st , int node){
        vis[node] = 1;
        
        for(int ele : adj[node]){
            if(!vis[ele]){
                dfs(adj , vis , st , ele);
            }
        }
        
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>> adj;
        
        for(auto ele : edges){
            adj[ele[0]].push_back(ele[1]);
        }
        
        vector<int> vis(V , 0);
        stack<int> st;
        
        for(int i = 0 ; i<V ; i++){
            if(!vis[i]){
                dfs(adj , vis, st , i);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
};

```

### TopoSort by using Breath First Search(Kahn's Algorithem)
```cpp

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
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
        
        return ans;
        
    }
};

```
