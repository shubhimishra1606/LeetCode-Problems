class Solution {
public:
    int solve(int r, int c, int i, int j, vector<vector<int>>& dp){
        if(i<0 || i>=r || j<0 || j>=c) return 0;
        if(i==r-1 && j==c-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=solve(r,c,i,j+1,dp)+solve(r,c,i+1,j,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m, n, 0, 0, dp);
    }
};