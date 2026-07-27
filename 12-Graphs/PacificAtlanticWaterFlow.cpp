class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int,int>> Pq;
        queue<pair<int,int>> Aq;
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        vector<vector<int>> ans;
        vector<int> chRow = {-1,1,0,0};
        vector<int> chCol = {0,0,-1,1};
        //for pacific, top row and left column
        //for atlantic, bottom row and right column
        for(int i=0;i<n;i++){
            Pq.push({i,0});
            pacific[i][0] = 1;
            Aq.push({i,m-1});
            atlantic[i][m-1] = 1;
        }
        for(int i=0;i<m;i++){
            Pq.push({0,i});
            pacific[0][i] =1;
            Aq.push({n-1,i});
            atlantic[n-1][i] = 1 ;
        }
        while(!Aq.empty()){
            int row = Aq.front().first;
            int col = Aq.front().second;
            Aq.pop();
            for(int i=0;i<4;i++){
                int newRow = row + chRow[i];
                int newCol = col + chCol[i];
                if(newRow < n && newRow >=0 &&
                newCol < m && newCol >=0 &&
                !atlantic[newRow][newCol] &&
                heights[newRow][newCol] >= heights[row][col]){
                    atlantic[newRow][newCol] = 1;
                    Aq.push({newRow,newCol});
                }
            }
        }
        while(!Pq.empty()){
            int row = Pq.front().first;
            int col = Pq.front().second;
            Pq.pop();
            for(int i=0;i<4;i++){
                int newRow = row + chRow[i];
                int newCol = col + chCol[i];
                if(newRow < n && newRow >=0 &&
                newCol < m && newCol >=0 &&
                !pacific[newRow][newCol] &&
                heights[newRow][newCol] >= heights[row][col]){
                    pacific[newRow][newCol] = 1;
                    Pq.push({newRow,newCol});
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};