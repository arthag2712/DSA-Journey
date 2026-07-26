class Solution {
public:
    /*
    NOTES:

    - A tree satisfies:
        1. Exactly n - 1 edges.
        2. Connected.

    - Graph Theory Fact:
    An undirected graph with n - 1 edges is a tree
    if and only if it is connected.

    - Therefore:
        - First check edges.size() == n - 1.
        - Then perform one DFS/BFS from any node.
        - If every node is visited, return true.

    - No explicit cycle detection is needed because
    with n - 1 edges, a connected graph cannot
    contain a cycle.

    - Time: O(V + E)
    - Space: O(V + E)
*/
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        for(auto adjNode : adj[node]){
            if(!vis[adjNode])
                dfs(adjNode, adj, vis);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if((n-1)!=edges.size()) return false;
        //make adj list
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        //run connectivity test
        vector<int> vis(n,0);
        dfs(0,adj,vis);
        for(int i=0;i<n;i++){
            if(!vis[i]) //if any node is still unvisited
                return false;
        }
        return true;
    }
};
