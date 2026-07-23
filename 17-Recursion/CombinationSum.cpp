class Solution {
public:
    vector<vector<int>> ans;
    void checkSubset(vector<int>& subAns, vector<int>& nums, int idx, int target, int currsum){
        if(currsum == target){
            ans.push_back(subAns);
            return;
        }
        if(idx==nums.size()) {
            return;
        }
        if(currsum > target){
            return; //since all numbers are +ve
        }
        //take
        subAns.push_back(nums[idx]);
        checkSubset(subAns,nums,idx,target,currsum+nums[idx]); //just idx since repition is allowed
        subAns.pop_back(); //backtrack: reset subAns before moving to not take
        //dont take
        checkSubset(subAns,nums,idx+1,target,currsum);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subAns;
        checkSubset(subAns,nums,0,target,0);
        return ans;
    }
};
