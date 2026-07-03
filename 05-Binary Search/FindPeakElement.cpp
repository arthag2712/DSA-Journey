class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n-2;
        if(n != 1 && nums[1]<nums[0]) return 0;
        if(n>=2 && nums[n-2]<nums[n-1]) return n-1;
        while(low<=high && n!=1){
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }else if(nums[mid]<nums[mid-1]){
                high = mid-1;
            }else{
                low=mid+1;
            }
        }
        return 0;
    }
};