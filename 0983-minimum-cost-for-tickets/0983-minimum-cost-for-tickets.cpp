class Solution {
public:
    int solve(int n, vector<int>& days, vector<int>& costs, int idx, vector<int>&dp){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int option1=costs[0]+solve(n,days,costs,idx+1,dp);
        int i=idx;
        while(i<n && days[i]<days[idx]+7) i++;
        int option2=costs[1]+solve(n,days,costs,i,dp);
        i=idx;
        while(i<n && days[i]<days[idx]+30) i++;
        int option3=costs[2]+solve(n,days,costs,i,dp);
        return dp[idx]=min({option1,option2, option3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        return solve(n, days, costs, 0,dp);
    }
};