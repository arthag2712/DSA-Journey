/*
NOTES:

- First tried generating both '(' and ')' every time, then pruning invalid states.
- Invalid if: close > open, open > n, or close > n.
- Forgot the second pop_back() -> temp is passed by reference, so every push/append needs a matching pop.
- open & close don't need undoing since they're passed by value.
- Better approach: only recurse if
    open < n
    close < open
  so invalid states are never generated.
*/
class Solution {
public:

    void generate(int n, string& temp, vector<string>& ans, int nOpen, int nClose){
        if(nOpen == nClose && nOpen == n){ //base case
            ans.push_back(temp);
            return;
        }
        if(nOpen < nClose || nOpen > n || nClose > n) return; //invalid case
        temp+="(";
        if(nOpen >= nClose && nOpen <= n && nClose <=n)
            generate(n,temp,ans,nOpen+1,nClose);
        temp.pop_back();
        temp+=")";
        if(nOpen >= nClose && nOpen <= n && nClose <=n)
            generate(n,temp,ans,nOpen,nClose+1);
        temp.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        generate(n,temp,ans,0,0);
        return ans;
    }
};
