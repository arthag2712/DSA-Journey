/*
FACED 2 ISSUES WITH CYCLE SORT:
1) MISSED CONDITION FOR IF THE NUMBER (nums[i]>n) then seg fault as nums[nums[i]-1] wouldn't exist
2) INFINITE LOOP IN CASE OF DUPLICATES IF nums[i] != i+1 is written
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        for(i=0;i<n;i++){
            while(nums[i]<=n && nums[i]>0 && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int k=0;k<n;k++){
            if(nums[k] != k+1) return k+1;
        }
        return n+1;
    }
};