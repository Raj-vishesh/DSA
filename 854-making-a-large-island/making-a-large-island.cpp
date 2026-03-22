class DSU{
    
    public:
    vector<int> parent , rank , size;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1 , 1);
        for(int i = 0 ; i < n ; i++){
            parent[i] =i;
        }
    }

    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

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

    

    
    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};


class Solution {
public:

    bool isValid(int newr , int newc, int n ){
        return newr>= 0 && newr < n && newc >= 0 && newc <n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n*n);
        //  STEP 1
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0) continue;
                int dr[] = {-1 , 0 , 1 , 0};
                int dc[] = {0 , 1 , 0 , -1};

                for(int idx = 0 ; idx < 4 ; idx++){
                    int newr = i + dr[idx];
                    int newc = j + dc[idx];
                    if(isValid(newr , newc , n ) && grid[newr][newc] == 1){
                        int nodeNo = i * n + j;
                        int adjNo = newr * n + newc;
                        ds.unionBySize(nodeNo , adjNo);   // FIXED
                        


                    }
                }
            }
        }

        // STEP 2 

        int mx =0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j <n ;j++){
                if(grid[i][j] ==1 ) continue;   
                int dr[] = {-1 , 0 , 1 , 0};
                int dc[] = {0 , 1 , 0 , -1}; 
                set<int> components;
                for(int idx = 0 ; idx < 4 ; idx++){
                    int newr = i + dr[idx];
                    int newc = j + dc[idx];
                    if(isValid(newr , newc , n )){
                        if(grid[newr][newc] == 1){
                            components.insert(ds.findParent(newr * n + newc));
                        }
                        
                    }
                }

                int total_size = 1;   // FIXED

                for(auto it : components){
                    total_size += ds.size[it];
                }
                mx = max(mx , total_size);

            }
        }

        for(int cell = 0; cell < n*n ; cell++){   // FIXED
            if(grid[cell/n][cell%n] == 1)         // FIXED
            mx= max(mx , ds.size[ds.findParent(cell)]);   // FIXED
        }

        return mx;
    }
};