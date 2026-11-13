class Solution {
    vector<long long> dijkstra(int n, const vector<vector<pair<int, int>>>& adj, int start) {
        vector<long long> dist(n, 1e15);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        dist[start] = 0;
        pq.push({0, start});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> adj(n), rev(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            rev[e[1]].push_back({e[0], e[2]});
        }
        auto d1 = dijkstra(n, adj, src1);
        auto d2 = dijkstra(n, adj, src2);
        auto d3 = dijkstra(n, rev, dest);
        long long ans = 1e18;
        for (int i = 0; i < n; ++i) {
            if (d1[i] < 1e15 && d2[i] < 1e15 && d3[i] < 1e15) {
                ans = min(ans, d1[i] + d2[i] + d3[i]);
            }
        }
        return ans > 1e17 ? -1 : ans;
    }
};