class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;
        for(int i = 0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int l=0;
        int r=nums.size()-1;
        vector<int> ans(2);
        while(l<r){
            int find = target-arr[l].first;
            if(arr[r].first>find) r--;
            else if(arr[r].first<find) l++;
            else {
                ans[0]=arr[l].second;
                ans[1]=arr[r].second;
                return ans;
            }
        }
        return ans;
    }
};