class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        vector<int> prefixSum(n,0);
        vector<int> postfixSum(n,0);
        int s1=0,s2=0;
        for(int i=0;i<n;i++){
            s1+=nums[i];
            s2+=nums[n-i-1];
            prefixSum[i]=s1;
            postfixSum[n-i-1]=s2;
        }
        for(int i=0;i<n;i++){
            if(i==0 && postfixSum[i+1]==0) return i;
            else if(i==n-1 && prefixSum[i-1]==0) return i;
            else if(i>0 && i<n-1 &&prefixSum[i-1]==postfixSum[i+1]) return i;
        }
        return -1;
    }
};