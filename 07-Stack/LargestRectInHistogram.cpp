class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        stack<int> p;
        for(int i=0;i<n;i++){
            while(!p.empty() && heights[i]<=heights[p.top()]){
                p.pop();
            }
            if(!p.empty()) pse[i]=p.top();
            p.push(i);
        }
        stack<int> nx;
        for(int i=n-1;i>=0;i--){
            while(!nx.empty() && heights[i]<=heights[nx.top()]){
                nx.pop();
            }
            if(!nx.empty()) nse[i]=nx.top();
            nx.push(i);
        }
        int maxArea = 0;
        for(int i=0;i<n;i++){
            maxArea = max(maxArea, (heights[i]*(nse[i]-pse[i]-1)));
        }
        return maxArea;
    }
};
