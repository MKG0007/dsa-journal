## Breath Frist Search:-
it is the traversal technique use to traversal the graph in level wise order.
#### in this method:- be use queue<>

```cpp
    vector<int> bfs(vector<vector<int>> &adj) {
        // in this code we are assuming that we have the graph in adjancency list format
        //so we don't have to convert it into one 
        int row = adj.size();// row representing number of vertex
        
        vector<int> vis(row , 0);//mark the nodes to avoid repetation
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int ele : adj[node]){
                if(!vis[ele]){
                    q.push(ele);
                    vis[ele] = 1;
                }
            }
        }
        
        
        return ans;
    }


```

## Depft First Search:-
it is another traversal technique for graph but in this we **use recursion for the traversal**

```cpp
  void dfs(vector<vector<int>> &adj , vector<int> &vis , vector<int> &ans , int node){//recursive function
      vis[node] = 1;
      ans.push_back(node);
      
      for(int ele : adj[node]){
          if(!vis[ele]){
              dfs(adj , vis , ans , ele);
          }
      }
  }
//dong same as we have done in bfs but in dfs we useing recursive approach instead of iterative

    vector<int> dfs(vector<vector<int>>& adj) {
        int vertex = adj.size();
        
        vector<int> vis(vertex , 0);
        vector<int> ans;
        
        dfs(adj , vis , ans , 0);
        
        return ans;
    }

```


### Note:- 
if there is multiple  components in the graph then we have to extra for loop to check the weather all nodes are visited or not   
if not visited then again call the traversal function for it.
```cpp
for(int i = 0 ; i<vertex ; i++){
  if(!vis[i]){
    dfs(i);//again traversal call
  }
}

```
