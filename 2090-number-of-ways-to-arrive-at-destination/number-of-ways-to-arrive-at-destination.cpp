class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1e9 +7; 
        vector<pair<int,int>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1] ,it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }

        vector<long long> dist(n , 1e18);

        vector<long long> ways(n,0);

        priority_queue<pair<long long, int> , vector<pair<long long ,int>> , greater<pair<long long ,int>>> pq;

        dist[0] =0;
        ways[0] = 1;

        pq.push({0 , 0});

        while(!pq.empty()){
            auto it = pq.top();
            long long d = it.first;
            int node = it.second;
            pq.pop();

            if(d > dist[node]) continue;


            for(auto neigh : adj[node]){
                int v = neigh.first;
                int wt = neigh.second;

                if(dist[node] + wt < dist[v] ){
                    dist[v] = dist[node] + wt;
                    ways[v] = ways[node];
                    pq.push({dist[v] , v});

                }

                else if(dist[node] + wt == dist[v]){
                    ways[v] = (ways[v] + ways[node] ) % mod;
                } 
            }


        }

        return ways[n-1];
    }
};