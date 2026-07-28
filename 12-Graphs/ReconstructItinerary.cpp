class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adj;
    vector<string> ans;

    void dfs(string airport){
        while(!adj[airport].empty()){ //while tickets for the current airport are unused
            auto nextAirport = adj[airport].top();
            adj[airport].pop(); //mark ticket as used
            dfs(nextAirport); //backtrack
        }
        ans.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto it : tickets){
            adj[it[0]].push(it[1]);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
