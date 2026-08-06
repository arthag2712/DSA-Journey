class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        //idea is to just identify which triplets are useless to form target
        // we don't actually need to merge the triplets

        bool gotFirst=false, gotSecond = false, gotThird = false;
        for(auto tpl : triplets){
            if(tpl[0] > target[0] || tpl[1] > target[1] || tpl[2] > target[2]) continue;
            if(tpl[0] == target[0]) gotFirst = true;
            if(tpl[1] == target[1]) gotSecond = true;
            if(tpl[2] == target[2]) gotThird = true;
        }
        if(gotFirst && gotSecond && gotThird) return true;
        return false;
    }
};
