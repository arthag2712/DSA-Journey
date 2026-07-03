/*
SOCHNE KA TARIKA:
IF NOT STANDARD BIN SEARCH:
VISUALIZE THE ARRAY AS RISING SLOPES
ASK YOURSELF IF MID LANDS ON SOMETHING, CAN I EXCLUDE MID?
IF YES THEN MID+1 OR MID-1, VARNA =MID, ALSO DON'T FORGET ABOUT L<R AND NOT L<=R, IT GIVES TLE
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r=n-1;
        int mid;
        while(l<r){
            mid = l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;               
            }else{
                r=mid;
            }
        }
        return nums[l];
    }
};