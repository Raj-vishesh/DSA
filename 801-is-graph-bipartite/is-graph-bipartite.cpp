class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n , -1);

        for(int i = 0 ; i< n ; i++){
            if(color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(int neigh : graph[node]){
                        if(color[neigh] == -1){
                            color[neigh] = 1 - color[node];
                            q.push(neigh);
                        }

                        if(color[neigh] == color[node]){
                            return false;
                        }
                    }

                }

            }
        }

       return true;

    }
};