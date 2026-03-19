class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<vector<pair<int,int>>> adj(n + 1);

        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int ,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        vector<int> dist(n+1 , 1e9);

        dist[k] = 0;

        pq.push({0 , k});


        while(!pq.empty()){
            auto[d , node] = pq.top();
            pq.pop();

            if(d > dist[node] ){
                continue;
            }

            for(auto neigh : adj[node]){
                int adjnode= neigh.first;
                int wt = neigh.second;

                if(dist[node] + wt < dist[adjnode]){
                    dist[adjnode] = dist[node]+ wt;

                    pq.push({dist[adjnode] , adjnode});
                } 


            }

        }

        int ans = 0;

        for(int i  = 1 ; i <= n ; i++){
            if(dist[i] == 1e9) return -1;
            ans = max(ans , dist[i]);
        }


        return ans;
    }
};