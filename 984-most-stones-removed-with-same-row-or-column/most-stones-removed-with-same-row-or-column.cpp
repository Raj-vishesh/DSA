class DSU {
    vector<int> parent, rank, size;

public:
    // Constructor
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find parent with path compression
    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    // Union by rank
    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Union by size
    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxrow = 0;
        int maxcol = 0;

        for(auto it: stones){
            maxrow = max(maxrow , it[0]);
            maxcol = max(maxcol , it[1]);

        }

        
        DSU ds(maxrow + maxcol +1);
        unordered_map<int,int> mp;
        for(auto it : stones){
            int noderow  = it[0];
            int nodecol = it[1] + maxrow + 1;
            ds.unionBySize(noderow, nodecol);
            mp[noderow] = 1;
            mp[nodecol] = 1;
        }

        int cnt = 0;
        for(auto it: mp){
            if(ds.findParent(it.first) == it.first){
                cnt++;
            }
        }

        return n - cnt;


        
        
    }
};