class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int idx = 0;
        int n = intervals.size();
        //intervals which end before the newInterval starts;
        while(idx < n && intervals[idx][1] < newInterval[0]){
            ans.push_back(intervals[idx]);
            idx++;
        }
        //merge overalapping intervals, till intervals[i] starts after newInterval ends
        while(idx < n && intervals[idx][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0],intervals[idx][0]);
            newInterval[1] = max(newInterval[1],intervals[idx][1]);
            idx++;
        }
        ans.push_back(newInterval);
        //push all remaining non-overlapping
        while(idx < n){
            ans.push_back(intervals[idx]);
            idx++; 
        }
        return ans;
    }
};
