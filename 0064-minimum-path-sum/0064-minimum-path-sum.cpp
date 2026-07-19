class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int r=grid.size(), c=grid[0].size();
        if(i==r-1 && j==c-1) return grid[i][j];
        if(i>=r || i<0 || j>=c || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=solve(grid, i, j+1, dp);
        int down=solve(grid, i+1, j, dp);
        return dp[i][j]=grid[i][j]+min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        vector<vector<int>>dp(r, vector<int>(c,-1));
        return solve(grid, 0, 0, dp);
    }
};