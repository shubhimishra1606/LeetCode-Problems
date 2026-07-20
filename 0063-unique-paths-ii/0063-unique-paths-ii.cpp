class Solution {
public:
    int solve(vector<vector<int>>& grid, int r, int c, int i, int j, vector<vector<int>>& dp){
        if(i>=r || i<0 || j>=c || j<0) return 0;
        if(i==r-1 && j==c-1) return 1;
        if(grid[i][j]==1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int right=solve(grid,r,c,i,j+1,dp);
        int down=solve(grid,r,c,i+1,j,dp);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r=obstacleGrid.size(), c=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[r-1][c-1]==1) return 0;
        vector<vector<int>>dp(r,vector<int>(c,0));
        // return solve(obstacleGrid,r,c,0,0,dp);

        dp[0][0]=1;
        for(int i=1; i<c; i++){
            if(obstacleGrid[0][i]==0){
                dp[0][i]=dp[0][i-1];
            }else{
                dp[0][i]=0;
            }
        }
        for(int i=1; i<r; i++){
            if(obstacleGrid[i][0]==0){
                dp[i][0]=dp[i-1][0];
            }else{
                dp[i][0]=0;
            }
        }
        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[r-1][c-1];
    }
};