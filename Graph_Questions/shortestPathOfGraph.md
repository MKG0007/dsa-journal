## shortest psth of the Graph:-
there are many ways and methods to find the shortest path 

### 1)using topoSort with breath first search:-
in this method we first find the toposhort of the graph by using dfs method and stored in the stack  
and then run the bfs on the stack and update the distance array with each iteration.  

**logic behind this method:**  
as in topo arrangement the last element of the graph will be the first in the sequance  
so from there we just start calculating and updating the distance for each nodes.


```cpp

class Solution {
public:
    void topo(unordered_map<int, vector<pair<int, int>>>& adj, vector<int>& vis,
              stack<int>& st, int node) {
        vis[node] = 1;

        for (auto ele : adj[node]) {
            int e = ele.first;
            if (!vis[e]) {
                topo(adj, vis, st, e);
            }
        }

        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<pair<int, int>>> adj;
        vector<int> vis(V, 0);
        stack<int> st;

        for (auto ele : edges) {
            adj[ele[0]].push_back({ele[1], ele[2]});
        }

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topo(adj, vis, st, i);
            }
        }

        vector<int> dis(V, 1e9);
        dis[0] = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            for (auto ele : adj[node]) {
                int e = ele.first;
                int w = ele.second;

                if (dis[node] + w < dis[e]) {
                    dis[e] = dis[node] + w;
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dis[i] == 1e9)
                dis[i] = -1;
        }

        return dis;
    }
};

```
---




## Djisktra's Algorithm:-
it is the famous method to find the shortest path for each node of the graph  
-we can use **priority queue**
-we can also use **set**
-and simple queue too(broot force)

but **set** data structure slightly better than **priority queue** because we can earase the old path from the **set** to avoid extra iterations  if we find any better path.  
but the diference is very minor as the erasing an element from the **set** takes **(logN)**-> time complexity


###note:-
Djisktra's Algorithm is not applicable on negative weight graph because of the infinite looping by negative weights as each time weight decreases at every addtion of the negative number. 
```cpp

// User function Template for C++
class Solution {
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto ele : edges) {
            adj[ele[0]].push_back({ele[1], ele[2]});
        }

        vector<int> dis(V, 1e9);

        dis[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        q.push({0, 0});

        while (!q.empty()) {
            int node = q.top().second;
            int wn = q.top().first;
            q.pop();

            for (auto ele : adj[node]) {
                int e = ele.first;
                int we = ele.second;

                if (wn + we < dis[e]) {
                    dis[e] = wn + we;

                    q.push({dis[e], e});
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dis[i] == 1e9)
                dis[i] = -1;
        }

        return dis;
    }
};



```


