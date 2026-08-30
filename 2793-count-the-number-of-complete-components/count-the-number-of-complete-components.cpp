class Solution {
public:

    void dfs(int node , vector<vector<int>> &adj , vector<int> &vis , int & v , int &e){

        vis[node] = 1;
        v++;
        e += adj[node].size();
        int n = adj.size();
        
        for(int neigh : adj[node]){
            if(!vis[neigh]){
                dfs(neigh , adj , vis , v  , e);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<int> vis(n , 0);
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            if(vis[i]){
                continue;
            }
            int v = 0 ; int e= 0;

            dfs(i , adj , vis , v , e);

            if(v * (v-1) == e){
                ans++;
            }
        }

        return ans;
        


    }
};
