class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < times.size() ; i++){
            int src = times[i][0];
            int dest = times[i][1];
            int tm = times[i][2];

            adj[src-1].push_back({dest-1 , tm});
        }

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> time(n , 1e9);
        
        int start = k-1;
        time[start] = 0;
        pq.push({0 , start});
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();

            int t = p.first;
            int node = p.second;

            if(t > time[node]){
                continue;
            }

            for(int i = 0 ; i < adj[node].size() ; i++){
                int neigh = adj[node][i].first;
                int tme = adj[node][i].second;

                if(t + tme < time[neigh]){
                    time[neigh] = t + tme;
                    pq.push({t + tme , neigh});
                }
            }
        }

        int max_t =  *max_element(time.begin() , time.end());

        if(max_t != 1e9){
            return max_t;
        }
        else return -1;


    }
};