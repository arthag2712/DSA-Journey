class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> vals;
        for(auto it : nums){
            if(vals.count(it)){
                return true;
            }else{
                vals.insert(it);
            }
        }
        return false;
    }
};