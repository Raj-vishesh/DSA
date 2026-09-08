class Solution {
public:

    bool valid(int r , int c , int n , int m){
        if(r < 0 || r >= n || c < 0 || c >= m){
            return false;
        }
        else return true;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
            // {{diff , {row, col}}}
        priority_queue<pair<int , pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        vector<vector<int>> dist(n , vector<int> (m , 1e9));

        int x[4] = {-1 , 1 , 0 , 0};
        int y[4] = {0 , 0 , 1, -1};
        
        dist[0][0] = 0;
        pq.push({0 , {0,0}});


        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(diff > dist[row][col]){
                continue;
            }      

            for(int i = 0; i < 4 ; i++){
                int newr = row + x[i];
                int newc = col + y[i];

                if(valid(newr , newc , n ,m) ){
                    int neweffort = max(abs(heights[row][col] - heights[newr][newc]) , diff );

                    if(neweffort < dist[newr][newc]){
                        dist[newr][newc] = neweffort;
                        pq.push({neweffort , {newr, newc}});
                    }
                }
            }

        }

        return dist[n-1][m-1]; 
    }
};