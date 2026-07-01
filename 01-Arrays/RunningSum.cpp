class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> rs(nums.size(),0);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            rs[i] = sum;
        }
        return rs;
    }
};