class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // vector<long long> preM(n,1);
        // vector<long long> postM(n,1);
        // long long s1=1,s2=1;
        // for(int i=0;i<n;i++){
        //     s1*=nums[i];
        //     s2*=nums[n-i-1];
        //     preM[i]=s1;
        //     postM[n-i-1]=s2;
        // }
        // vector<int> ans(n);
        // for(int i=0;i<n;i++){
        //     if(i==0) ans[i]=postM[i+1];
        //     else if(i==n-1) ans[i]=preM[i-1];
        //     else ans[i] = preM[i-1]*postM[i+1];
        // }

        //SPACE OPTIMISED
        vector<int> ans(n);
        int currPrefix=1,currSuffix=1;
        for(int i=0;i<n;i++){
            ans[i]=currPrefix;
            currPrefix*=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            ans[i]*=currSuffix;
            currSuffix*=nums[i];
        }
        return ans;
    }
};