class Solution {
public:  
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        int n=matrix.size();
        if(j<0 || j>=n) return 1e9;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int first=solve(matrix,i+1,j-1,dp);
        int second=solve(matrix,i+1,j,dp);
        int third=solve(matrix,i+1,j+1,dp);
        return dp[i][j]=matrix[i][j]+min({first,second,third});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum=INT_MAX, n=matrix.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // for(int i=0; i<matrix.size(); i++){
        //     minSum=min(minSum, solve(matrix,0,i,dp));
        // }
        // return minSum;

        //-----------TABULATION(cuz memo gives tle)--------
        for(int i=0; i<n; i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int first=((j==0)?1e9:dp[i+1][j-1]);
                int second=dp[i+1][j];
                int third=((j==n-1)?1e9:dp[i+1][j+1]);
                dp[i][j]=matrix[i][j]+min({first,second,third});
            }
        }
        for(int i=0; i<n; i++){
            minSum=min(minSum,dp[0][i]);
        }
        return minSum;
    }
};