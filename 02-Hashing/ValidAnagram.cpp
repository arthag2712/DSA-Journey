class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> frq(26,0);
        for(auto ch1 : s){
            frq[ch1-'a']++;
        }
        for(auto ch2 : t){
            frq[ch2-'a']--;
        }
        for(auto it : frq){
            if(it != 0)
                return false;
        }
        return true;
    }
};
