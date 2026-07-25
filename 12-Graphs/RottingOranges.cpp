class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int mins =0;
        int n=grid.size();
        int m = grid[0].size();
        // vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }
        vector<int> chRow = {-1,1,0,0};
        vector<int> chCol = {0,0,-1,1};
        while(!q.empty()){
            int minPassed = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int newRow = row + chRow[i];
                int newCol = col + chCol[i];
                if(newRow < grid.size() && newRow >=0 &&
                newCol < grid[0].size() && newCol >=0 &&
                grid[newRow][newCol]==1){
                    grid[newRow][newCol]=2;
                    q.push({minPassed + 1 ,{newRow,newCol}});
                }
            }
            mins = minPassed + 1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return mins>0 ? mins-1 : mins;
    }
};
