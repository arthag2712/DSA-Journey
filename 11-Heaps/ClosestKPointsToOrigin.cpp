class Solution {
public:
    double dist(vector<int> point){
        return sqrt(point[0]*point[0] + point[1]*point[1]);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> pq;
        for(auto point : points){
            pq.push({dist(point),point});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
