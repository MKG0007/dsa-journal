## find the distance form each shell to its nearest zero 

in this we have to find the distance between the nearest Zero form any cell 
so , the shell which is zero has distance zero(he itself is the nearest zero)

we will use the reverse approach --> we will take all the zeroes as a starting traversal and marks the shell with distance 1 at the first round  
and when the marked ones mark its neighbours they will update there distances --->(source[distance]+1)  
```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> vis(row , vector<int>(col , 0));
        vector<vector<int>> ans(row , vector<int>(col , 0));
        vector<pair<int , int>> dec = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}};
    

        queue<pair<int , int>> q;
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(mat[i][j] == 0){
                    q.push({i , j});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            for(auto d : dec){
                int dx = d.first + i;
                int dy = d.second + j;

                if(0<=dx && 0<=dy && dx<row && dy<col && !vis[dx][dy]){
                    ans[dx][dy] = ans[i][j]+1;
                    vis[dx][dy] = 1;
                    q.push({dx , dy});
                    
                }
            }
        }
        
    return ans;
    }

};

```


