class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        int mn=INT_MAX;
        for(int i: coins){
            int ans=solve(coins,amount-i,dp);
            if (ans!=INT_MAX) mn=min(mn,1+ans);
        }
        dp[amount]=mn;
        return mn;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans=solve(coins,amount,dp);
        return (ans==INT_MAX) ? -1 : ans;
    }
};