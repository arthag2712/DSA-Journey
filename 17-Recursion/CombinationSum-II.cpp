class Solution {
public:
    vector<vector<int>> ans;

    void checkSubset(vector<int>& subAns, vector<int>& nums, int idx, int target, int currsum){
        if(currsum == target){
            ans.push_back(subAns);
            return;
        }

        if(idx == nums.size() || currsum > target) {
            return;
        }

        // Skip all duplicates in the don't-take path
        int copyIdx = idx + 1;
        while(copyIdx < nums.size() && nums[copyIdx] == nums[copyIdx - 1]){
            copyIdx++; //since no dups allowed
        }

        //take
        subAns.push_back(nums[idx]);
        checkSubset(subAns, nums, idx + 1, target, currsum + nums[idx]);
        subAns.pop_back(); //backtrack: reset subAns before moving to not take

        //dont take
        checkSubset(subAns, nums, copyIdx, target, currsum);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> subAns;
        sort(nums.begin(), nums.end()); // Sort so duplicates are adjacent
        checkSubset(subAns, nums, 0, target, 0);
        return ans;
    }
};