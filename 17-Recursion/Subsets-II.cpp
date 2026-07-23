class Solution {
public:
    vector<vector<int>> ans;
    void makeSubsets(vector<int>& nums, int idx, vector<int>& temp){
        if(idx==nums.size()) {
            ans.push_back(temp);
            return;
        }
        int copyIdx = idx+1;
        while(copyIdx<nums.size() && nums[copyIdx]==nums[copyIdx-1]) copyIdx++;
        temp.push_back(nums[idx]);
        makeSubsets(nums,idx+1,temp);
        temp.pop_back(); //remember to pop last element as that goes into not-take case
        makeSubsets(nums,copyIdx,temp); //use the non-repeating for not-take case
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        makeSubsets(nums,0,temp);
        return ans;
    }
};
