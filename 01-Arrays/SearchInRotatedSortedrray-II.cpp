#include <bits/stdc++.h>
using namespace std;
/*
MAJOR THING WAS TO IDENTIFY THE CASE WHERE a[low]==arr[mid]==arr[high]
THAT'S THE CASE WHERE THE PREVIOUS (I) WALA CODE WOULD FAIL
SO THE IDEA IS WHEN THAT CONDITION OCCURS INCREMENT LEFT AND DECREMENT RIGHT POINTERS,
UNTIL THE CONDITION IS DISSATISFIED.
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0, high=n-1,mid;
        while(low<=high){
            mid = low + (high-low)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[low] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
            if(nums[mid] <= nums[high]){
                //right half sorted
                if(nums[mid]<target && nums[high]>=target){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }else{
                //left half is sorted
                if(nums[mid]>target && nums[low]<=target){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
        }
        return false;
    }
};