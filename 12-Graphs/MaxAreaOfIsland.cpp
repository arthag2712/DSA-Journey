/*
NOTES:

- Correct approach is Multi-Source BFS:
  - Push all treasures (0s) into the queue initially.
  - BFS expands from all treasures simultaneously.

- Initially tried using a local variable 'mini'.
  - It reset for every node, so distances beyond 1 were impossible.

- Initially forgot to push newly discovered rooms into the queue.
  - Without this, BFS stops after processing only the treasures.

- Initially incremented 'currdist' inside the neighbour loop.
  - This incorrectly gave different distances to neighbours of the same cell.
  - All neighbours should receive (current distance + 1).

- Initially pushed {currdist, ...} into the queue.
  - The neighbour itself is at (currdist + 1), so the queue must store that value.

- Initially thought a room should be updated if another treasure reaches it.
  - In Multi-Source BFS, the first time an INF room is discovered is already its
    shortest distance, so it should never be processed again.

- 'currdist++' after processing the neighbours is unnecessary.
  - The variable is local to the current iteration and is never used again.

- Cleaner implementation:
  - Store only (row, col) in the queue.
  - Use grid[row][col] as the current distance instead of storing distance
    separately in the queue.
*/
class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[row][col] = 1;
        int maxArea = 1;
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
                !vis[newRow][newCol] && grid[newRow][newCol]==1){
                    vis[newRow][newCol] = 1;
                    q.push({newRow,newCol});
                    maxArea++;
                }
            }
        }
        return maxArea;        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int area = bfs(i,j,grid,vis);
                    ans = max(area,ans);
                }
            }
        }
        return ans;
    }
};
