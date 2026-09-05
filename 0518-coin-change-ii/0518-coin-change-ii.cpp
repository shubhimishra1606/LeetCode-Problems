class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<vector<int>>& dp, int idx){
        if(amount==0) return 1;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int count=0;
        for(int i=idx; i<coins.size(); i++){
           if(amount>=coins[i]) count+=solve(coins, amount-coins[i], dp, i);
        }
        dp[idx][amount]=count;
        return count;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1,-1));
        return solve(coins, amount, dp, 0);
    }
};