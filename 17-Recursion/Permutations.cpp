class Solution {
public:

    void recurseAns(vector<int>& nums, vector<int>& used, vector<int>& temp, vector<vector<int>>& ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            temp.push_back(nums[i]);
            used[i]=1;
            recurseAns(nums,used,temp,ans);
            used[i]=0;
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(),0);
        vector<int> temp;
        vector<vector<int>> ans;
        recurseAns(nums,used,temp,ans);
        return ans;
    }
};
