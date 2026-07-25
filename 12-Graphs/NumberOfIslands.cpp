class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        vector<int> chRow = {-1,1,0,0};
        vector<int> chCol = {0,0,-1,1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newRow = row + chRow[i];
                int newCol = col + chCol[i];
                if(newRow < grid.size() && newRow >=0 &&
                newCol < grid[0].size() && newCol >=0 &&
                !vis[newRow][newCol] && grid[newRow][newCol]=='1'){
                    vis[newRow][newCol] = 1;
                    q.push({newRow,newCol});
                }
            }
        }        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};
