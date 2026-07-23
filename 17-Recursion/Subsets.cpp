class Solution {
public:
    vector<vector<int>> ans;
    void makeSubsets(vector<int>& nums, int idx, vector<int>& temp){
        if(idx==nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        makeSubsets(nums,idx+1,temp);
        temp.pop_back(); //remember to pop last element as that goes into not-take case
        makeSubsets(nums,idx+1,temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        makeSubsets(nums,0,temp);
        return ans;
    }
};
