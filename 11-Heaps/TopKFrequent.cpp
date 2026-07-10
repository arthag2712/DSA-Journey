class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto it : nums){
            mpp[it]++;
        }
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // for(auto it : mpp){
        //     pq.push({it.second,it.first});
        //     if(pq.size()>k){
        //         pq.pop();
        //     }
        // }
        // vector<int> ans;
        // while(k--){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return ans;

        /*MOST OPTIMAL APPROACH : BUCKET SORT*/
        int n = nums.size();
        vector<vector<int>> buckets(n+1);
        for(auto it : mpp){
            buckets[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i = n;i>=0 && ans.size() < k ;i--){
            if(!buckets[i].empty()){
                for(auto it : buckets[i]){
                    if(ans.size()==k) break;
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};
