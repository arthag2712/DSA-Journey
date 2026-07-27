class DisjointSet {
public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }

    int findUPar(int u){
        if(u == parent[u])
            return u;
        return parent[u] = findUPar(parent[u]); //path compression step
    }

    void unionBySize(int u, int v){
        int ulp_v = findUPar(v);
        int ulp_u = findUPar(u);
        if(ulp_v == ulp_u) return;
        if(size[ulp_v] <= size[ulp_u]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution {
public:
    /*
    since a tree has only one path between two nodes, 
    adding one more edge bw the two except for UPar would create two paths, hence that is the edge itself
    */
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        DisjointSet ds(n);
        for(auto it : edges){
            if(ds.findUPar(it[0])==ds.findUPar(it[1])) return {it[0],it[1]};
            ds.unionBySize(it[0],it[1]);
        }
        return {};
    }
};
