/*
Problem pattern -> Sliding Window with Map/Frequency storage
Points I missed: Using startIndex instead of l-1 for computing substring 
*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> s_map;
        unordered_map<char,int> t_map;
        for(auto it : t){
            t_map[it]++;
        }
        int tLen = t_map.size();
        int l=0,r=0, minLen=INT_MAX;
        string ans="";
        int n = s.size();
        int countMatch=0;
        int startIndex=0;
        while(r<n){
            s_map[s[r]]++;
            if(t_map.count(s[r]) && t_map[s[r]]==s_map[s[r]]){
                countMatch++;
            }
            while(countMatch==tLen){   
                if(minLen > r-l+1){
                    startIndex = l;
                    minLen = r-l+1;
                }
                s_map[s[l]]--;
                if(t_map.count(s[l]) && t_map[s[l]]>s_map[s[l]]){
                    countMatch--;
                }
                l++;
            }
            r++;
        }
        ans = (minLen != INT_MAX) ? s.substr(startIndex,minLen) : "";
        return ans;
    }
};