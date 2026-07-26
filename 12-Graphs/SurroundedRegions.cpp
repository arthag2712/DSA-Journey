//idea is to traverse possible O's from boundary and mark them as not changed to X
//rest of the remaining O's would be changed
class Solution{
public:
    void solve(vector<vector<char>>& mat) {
       int n = mat.size();
       int m = mat[0].size();
       vector<vector<int>> vis(n, vector<int>(m,0));
       queue<pair<int,int>> q;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(mat[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
       }
       vector<int> chRow = {0,0,-1,1};
       vector<int> chCol = {-1,1,0,0};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newRow = row + chRow[i];
                int newCol = col + chCol[i];
                if(newCol>=0 && newCol<m && newRow>=0 && newRow<n
                && mat[newRow][newCol]=='O' && vis[newRow][newCol]==0){
                    q.push({newRow,newCol});
                    vis[newRow][newCol]=1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
    }
};