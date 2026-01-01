class Solution {
public:

    int dfs(vector<vector<int>>& grid, vector<int>&dp, int i, int j){

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() ){
            return INT_MAX;
        }

        if ( dp[i * 200 + j ]  != -1 ){
            return dp[i * 200 + j ];
        }

        if (i == grid.size()-1 && j == grid[i].size()-1){
            dp[(i * 200) + j ] = grid[i][j];
            return grid[i][j];
        }
        
        dp[i * 200 + j ] = grid[i][j] + min( dfs(grid,dp, i+1, j), dfs(grid,dp, i, j+1) );
        return dp[i * 200 + j ];

    }

    int minPathSum(vector<vector<int>>& grid) {

        vector<int>dp(201*201, -1);
        return dfs(grid,dp, 0,0);
    }
};
