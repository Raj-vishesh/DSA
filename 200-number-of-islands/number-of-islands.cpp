class Solution {
public:

    void dfs(int r , int c , vector<vector<char>> & grids){
        int n = grids.size();
        int m = grids[0].size();

        if(r< 0 || r >= n || c < 0 || c >= m || grids[r][c] == '0'){
            return ;
        }

        grids[r][c] = '0';

        dfs(r-1 , c , grids);
        dfs(r , c+1 , grids);
        dfs(r+1 , c ,grids);
        dfs(r, c-1 , grids);



    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i , j , grid);
                }
            }
        }

        return cnt;
    }
};