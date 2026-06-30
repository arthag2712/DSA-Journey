class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp; //stores prefix sum,count
        int n = nums.size();
        long long sum=0;
        int count = 0;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mpp.find(sum-k)!=mpp.end()){
                count += mpp[sum-k];
            }
            mpp[sum]++;
        }
        return count;
    }
};