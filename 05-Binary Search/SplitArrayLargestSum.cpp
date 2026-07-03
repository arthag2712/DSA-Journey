class Solution {
public:
    /*
    TO CHECK IF A SUM IS POSSIBLE, TRAVERSE THE ARRAY ALWAYS KEEPING THE SUM<=MID
    IF NUMBER OF PARTITIONS REQUIRED > K-1 (SINCE K IS NO. OF SECTIONS NOT PARTITIONS),
    THEN RETURN FALSE AS IT IS NOT POSSIBLE, ELSE RETURN TRUE;
    */
    bool isPossible(long long mid, vector<int>& nums, int k){
        long long sum=0;
        int n = nums.size();
        long long noPart = 0;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }else{
                sum=0;
                noPart++;
                sum+=nums[i];
            }
        }
        if(noPart>k-1) return false;
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum=0;
        for(auto it : nums) sum+=it;
        long long low= *max_element(nums.begin(), nums.end()), high=sum;
        int ans;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(isPossible(mid,nums,k)){
                ans = mid;
                high = mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};