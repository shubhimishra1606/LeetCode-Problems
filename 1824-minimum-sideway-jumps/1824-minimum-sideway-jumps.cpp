class Solution {
public:
    int solve(vector<int>& obs, int lane, int pos, vector<vector<int>>& dp){
        if(pos==obs.size()-1){
            return 0;
        }
        if(dp[lane][pos]!=-1) return dp[lane][pos];
        if(obs[pos+1]!=lane){
            return solve(obs, lane, pos+1, dp);
        }else{
            int ans=INT_MAX;
            for(int i=1; i<=3; i++){
                if(lane!=i && obs[pos]!=i){
                    ans=min(ans,1+solve(obs,i,pos,dp));
                }
            }
            return dp[lane][pos]=ans;
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>>dp(4,vector<int>(obstacles.size(),-1));
        return solve(obstacles,2,0,dp);
    }
};