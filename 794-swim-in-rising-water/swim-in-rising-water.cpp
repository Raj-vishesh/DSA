class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int ,pair<int,int>>  , vector<pair<int,pair<int,int>>> , greater<pair<int, pair<int,int>>>> pq;

        vector<vector<bool>> vis(n , vector<bool> (n , false));

        vector<pair<int,int>> dir{{-1,0} ,{0,1} , {1,0} , {0,-1}};
        pq.push({grid[0][0] , {0 , 0}});

        vis[0][0] = true;


        while(!pq.empty()){
            pair<int, pair<int,int>> current = pq.top();
            pq.pop();


            int t= current.first;
            int r = current.second.first;
            int c = current.second.second;
            
            if(r == n-1 && c == n-1){
                return t;

            }

            for(int i = 0 ; i < 4 ; i++){
                int nr = r + dir[i].first;
                int nc = c + dir[i].second;

                if(nr >= 0 && nc >= 0 && nr < n && nc < n && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    int maxt_t = max(t , grid[nr][nc]);
                    pq.push({maxt_t , {nr , nc}});
                }
            }
        }

        return -1;
    }
};