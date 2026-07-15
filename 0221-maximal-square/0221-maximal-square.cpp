class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int mx=0, r=mat.size(), c=mat[0].size();
        vector<vector<int>>dp(r+1, vector<int>(c+1,0));
        for(int i=r-1; i>=0; i--){
            for(int j=c-1; j>=0; j--){
                int right=dp[i][j+1];
                int down=dp[i+1][j];
                int diagonal=dp[i+1][j+1];
                if(mat[i][j]=='1'){
                    dp[i][j]=1+min({right,down,diagonal});
                    mx=max(dp[i][j],mx);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return mx*mx;
    }
};