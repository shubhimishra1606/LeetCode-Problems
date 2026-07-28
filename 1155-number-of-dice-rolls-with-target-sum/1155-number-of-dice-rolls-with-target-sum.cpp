class Solution {
public:
    long long   MOD=1e9+7;  
    int solve(int n, int k, int target, vector<vector<int>>& dp){
        if(target<0) return 0;
        if(n==0 && target!=0) return 0;
        if(target==0 && n!=0) return 0;
        if(n==0 && target==0) return 1;
        if(dp[n][target]!=-1) return dp[n][target];
        long long ans=0;
        for(int i=1; i<=k; i++){
            ans=ans+solve(n-1, k, target-i,dp);
        }
        return dp[n][target]=ans%MOD;
    }
    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // return solve(n,k,target,dp);

        //---------TABULATION--------
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
                long long ans=0;
                for(int x=1; x<=k; x++){
                    if(j-x>=0){
                        ans=(ans+dp[i-1][j-x])%MOD;
                    }
                }
                dp[i][j]=ans;
            }
        }
        return dp[n][target]%MOD;
    }
};