class Solution {
public:
    int solve(vector<int>& piles, int st, int end, vector<vector<int>>& dp){
        if(st==end) return piles[st];
        if(dp[st][end]!=-1) return dp[st][end];
        int left=piles[st]-solve(piles, st+1, end, dp);
        int right=piles[end]-solve(piles, st, end-1, dp);
        return dp[st][end]=max(left,right);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return solve(piles,0,n-1,dp)>0;
    }
};