class Solution {
public:
    int solve(vector<vector<char>>& mat, int i, int j, int& mx, vector<vector<int>>& dp){
        if(i>=mat.size() || j>=mat[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=solve(mat, i, j+1, mx, dp);
        int down=solve(mat, i+1, j, mx, dp);
        int diagonal=solve(mat, i+1, j+1, mx, dp);
        if(mat[i][j]=='1'){
            int ans=1+min({right, diagonal, down});
            mx=max(mx, ans);
            return dp[i][j]=ans;
        }else{
            return dp[i][j]=0;
        }

    }
    int maximalSquare(vector<vector<char>>& mat) {
        int r=mat.size(), c=mat[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));
        int mx=0;
        solve(mat,0,0,mx,dp);
        return mx*mx;
    }
};