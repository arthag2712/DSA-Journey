class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0}); //storing as {wt,pointIndex}
        int sum = 0;
        vector<int> vis(n,0);
        while(!pq.empty()){
            int wt = pq.top().first;
            int pId = pq.top().second;
            pq.pop();
            if(vis[pId]) continue;
            sum+=wt;
            vis[pId] = 1;
            for(int i = 0; i < n;i++){
                if(vis[i]) continue;
                int manD = (abs(points[i][0]-points[pId][0]) + abs(points[i][1]-points[pId][1]));
                pq.push({manD,i});
            }
        }
        return sum;
    }
};