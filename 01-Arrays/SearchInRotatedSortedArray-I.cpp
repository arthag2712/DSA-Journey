/*
ALWAYS REMEMBER THAT ON ROTATING THE ARRAY, AND DIVIDING IT THROUGH MID, ALWAYS ONE HALF WOULD ALREADY BE SORTED
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r=n-1;
        int mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>nums[r]){ //left half is sorted
                if(nums[mid] > target && nums[l] <= target){
                    r = mid-1;
                }
                else{
                    l=mid+1;
                }
            }else{ //right half is sorted
                if(nums[mid]<target && nums[r] >= target){
                    l=mid+1;
                }else{   
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};