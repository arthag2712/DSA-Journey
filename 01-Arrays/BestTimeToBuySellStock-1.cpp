class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxi = 0;
        int n = prices.size();
        for(int i=0;i<n;i++){
            mini = min(prices[i],mini);
            maxi = max(maxi, prices[i]-mini);
        }
        return maxi;
    }
};