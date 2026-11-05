class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n + 1, INT_MAX);

        // Min heap: {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {

            auto [d, u] = pq.top();
            pq.pop();

            // Ignore outdated entries
            if(d > dist[u]) continue;

            for(auto [v, w] : adj[u]) {

                if(dist[v] > d + w) {

                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int answer = 0;

        for(int i = 1; i <= n; i++) {

            if(dist[i] == INT_MAX) return -1;

            answer = max(answer, dist[i]);
        }

        return answer;
    }
};