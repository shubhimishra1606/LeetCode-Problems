class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        int mn=INT_MAX;
        for(int idx=1; idx*idx<=n; idx++){
            mn=min(mn, 1+solve(n-idx*idx,dp));
        }
        return dp[n]=mn;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};