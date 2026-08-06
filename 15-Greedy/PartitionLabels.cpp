class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char,int> last;
        for(int i=0;i<n;i++){
            last[s[i]]=i;
        }
        int start=0, end=0;
        vector<int> ans;
        while(start < n && end < n){
            end=last[s[start]];
            for(int i=start;i<=end;i++){
                end = max(end,last[s[i]]);
            }
            ans.push_back(end-start+1);
            start=end+1;
        }
        return ans;
    }
};
