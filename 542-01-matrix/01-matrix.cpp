class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        
        vector<vector<int>> vis(n , vector<int> (m, 0));

        vector<vector<int>> dist(n , vector<int> (m,0));
        queue<pair<int , int>> q;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j< m; j++){
                if(mat[i][j] == 0){
                    q.push({i , j});
                    vis[i][j] = 1;
                }
            }
        }

        int delrow[4] = { -1 , 0 , +1 , 0};

        int delcol[4] = { 0 , +1 , 0 , -1};


        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
        


            for(int i = 0 ; i< 4 ; i++){
                int nrow = row + delrow[i];

                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
                    dist[nrow][ncol] = dist[row][col] +1;
                    vis[nrow][ncol] =1;
                    q.push({nrow , ncol});
                }
            }
        }
        return dist;
    }
};