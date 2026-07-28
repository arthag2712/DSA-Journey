class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]}); //stores node,wt
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k}); //pq stores dist,node
        dist[k]=0;
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(d > dist[node]) continue;
            for(auto neigh : adj[node]){
                int edgeWt = neigh.second;
                int newNode = neigh.first;
                if(d + edgeWt < dist[newNode]){
                    dist[newNode] = d + edgeWt;
                    pq.push({dist[newNode],newNode});
                }
            }
        }
        int maxi = *max_element(dist.begin()+1,dist.end());
        return maxi != INT_MAX ? maxi : -1;
    }
};
