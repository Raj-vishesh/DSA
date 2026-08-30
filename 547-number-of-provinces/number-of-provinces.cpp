class Solution {
public:

    void dfs(vector<vector<int>> &isConnected , int node , vector<int> &vis){
        vis[node] = 1;
        int n = isConnected.size();

        for(int i  = 0 ; i < n ; i++ ){
            if(isConnected[node][i] == 1 && !vis[i]){
                dfs(isConnected , i , vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n ,0);
        int cnt = 0;

        for(int i = 0 ; i< n  ; i++){
            if(!vis[i]){
                cnt++;
                dfs(isConnected , i , vis);
            }
        }
        return cnt;

    }
};