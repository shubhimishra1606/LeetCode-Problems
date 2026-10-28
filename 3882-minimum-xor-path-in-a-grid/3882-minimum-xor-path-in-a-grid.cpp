class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int num, vector<vector<vector<int>>>& dp){
        int r=grid.size(), c=grid[0].size();
        if(i>=r || i<0 || j>=c || j<0) return 1e9;
        num^=grid[i][j];
        if(i==r-1 && j==c-1) return num;
        if(dp[i][j][num]!=-1) return dp[i][j][num];
        int right=solve(grid, i, j+1, num, dp);
        int down=solve(grid, i+1, j, num, dp);
        return dp[i][j][num]=min(right, down);
    }

    int minCost(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(1024,-1)));
        return solve(grid, 0, 0, 0, dp);
    }
};