class Solution {
public:
    int solve(vector<int>& values, int ans, int i, int j, vector<vector<int>>& dp){
        if(i+1==j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k=i+1; k<j; k++){
            ans=min(ans,values[i]*values[j]*values[k]+solve(values,ans,i,k,dp)+solve(values,ans,k,j,dp));
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int ans=INT_MAX, n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(values,ans,0,n-1,dp);
    }
};