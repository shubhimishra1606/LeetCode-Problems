class Solution {
public:
    int solve(vector<int>& nums, int i, int t, vector<vector<int>>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i][t] != INT_MIN) return dp[i][t];
        int include=nums[i]*(t) + solve(nums, i+1, t+1, dp);
        int exclude=solve(nums, i+1, t, dp);
        dp[i][t]=max(include, exclude);
        return dp[i][t];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return solve(satisfaction,0,1,dp);

        dp[n][n]=0;
        for(int i=n-1; i>=0; i--){
            for(int j=i; j>=0; j--){
                int include=satisfaction[i]*(j+1) +dp[i+1][j+1];
                int exclude=dp[i+1][j];
                dp[i][j]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
};