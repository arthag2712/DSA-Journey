class Solution {
public:
    int isValid(string& s, int idx, int cnt, vector<vector<int>>& dp){
        if(cnt < 0 || cnt > s.size()) return 0;
        if(idx == s.size()){
            if(cnt == 0) return dp[idx][cnt] = 1;
            else return dp[idx][cnt] = 0;
        }  
        if(dp[idx][cnt] != -1) return dp[idx][cnt];
        if(s[idx]=='(') return dp[idx][cnt] = isValid(s,idx+1,cnt+1,dp);
        else if(s[idx]==')') return dp[idx][cnt] = isValid(s,idx+1,cnt-1,dp);
        else return dp[idx][cnt] = (isValid(s,idx+1,cnt+1,dp) || isValid(s,idx+1,cnt-1,dp) || isValid(s,idx+1,cnt,dp));
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return isValid(s,0,0,dp);
    }
};
//asterisk wala parentheses string validation