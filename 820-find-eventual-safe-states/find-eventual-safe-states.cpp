class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();

        vector<vector<int>> adj(n);
        vector<int> indegree(n , 0);

        

        for(int i = 0; i < n ; i++){
            for(auto it: graph[i]){
                adj[it].push_back(i);
            }
        }

        for(int i = 0 ; i < n ; i++){
            indegree[i] = graph[i].size();
        }

        queue<int> q;

        for(int i = 0 ; i < n ; i++){
            if(indegree[i] ==0 ){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        sort(topo.begin() , topo.end());

        return topo;
    }
};