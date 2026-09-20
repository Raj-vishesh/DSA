class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        int ans = 0;
        map<vector<int> ,int> mp;
        for(auto & row  : grid){
            mp[row]++;
        }

        for(int col = 0 ; col < n ; col++){
            vector<int> columns;

            for(int row = 0 ; row < n ; row++){
                columns.push_back(grid[row][col]);
            }

            ans += mp[columns];
        }

        return ans;
    }
};