class Solution {
public:

    bool res = true;

    void dfs(vector<vector<int>> &graph , int node, int color , vector<int> &colors){

        colors[node] = color;
        for(int i = 0 ; i < graph[node].size() ; i++){
            int neigh = graph[node][i];

            if(colors[neigh] != -1 && colors[neigh] == color){
                res = false;
            }
            else if(colors[neigh] == -1){
                dfs(graph , neigh , 1-color , colors);
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n , -1);

        for(int i = 0 ; i < n ; i++){
            if(colors[i] == -1){
                dfs(graph , i , 0 , colors);
            }
        }

        return res;
    }
};