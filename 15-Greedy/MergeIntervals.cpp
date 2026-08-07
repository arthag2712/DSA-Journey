class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        auto curr = intervals[0];
        vector<vector<int>> ans;
        for(auto itv : intervals){
            if(itv[0] <= curr[1]){
                //overlapping -> merge
                curr[0] = min(curr[0],itv[0]);
                curr[1] = max(curr[1],itv[1]);
            }else{
                ans.push_back(curr);
                curr = itv;
            }
        }
        ans.push_back(curr);
        return ans;
    }
};
