class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        queue<pair<int,pair<int,int>>> q; //stored as dist, row, col
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({0,{i,j}});
                }
            }
        }
        vector<int> chRow = {-1,1,0,0};
        vector<int> chCol = {0,0,-1,1};
        while(!q.empty()){
            int currdist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int newRow = row + chRow[i];
                int newCol = col + chCol[i];
                if(newRow < grid.size() && newRow >=0 &&
                newCol < grid[0].size() && newCol >=0 &&
                grid[newRow][newCol]==INT_MAX){
                    grid[newRow][newCol] = currdist+1;
                    q.push({currdist+1,{newRow,newCol}});
                }
            }
            currdist++;
        }
    }
};
 