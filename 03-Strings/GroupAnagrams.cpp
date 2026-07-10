/*
STORE FREQ OF EVERY STRING IN A FREQ ARRAY, CONVERT THE FREQ ARRAY TO STRING
USAGE OF DELIMITER IS VV IMP AS DIFFERENT STRINGS MAY PRODUCE THE SAME STRING
USE THIS AS KEY FOR MAP AND PLACE STRINGS WITH THAT TEMPLATE INTO THE KEY VALUE
RETURN MPP[KEY];
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(auto s : strs){
            vector<int> freq(26,0);
            for(auto it : s){
                freq[it-'a']++;
            }
            string key;
            for(auto x : freq){
                key+=to_string(x);
                key+='#'; //USAGE OF DELIMITER V V IMP
            }
            mpp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
