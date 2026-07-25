class Solution {
public:
    int solve(vector<int>& nums, int st, int end, int n, vector<vector<int>>& dp){
        if(st>end || n==0) return 0;
        if(dp[st][n]!=-1) return dp[st][n];
        int include=nums[st]+solve(nums, st+2, end, n-1, dp);
        int exclude=solve(nums, st+1, end, n, dp);
        return dp[st][n]=max(include,exclude);
    }
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        vector<vector<int>>dp1(n+1,vector<int>(n+1,-1));
        int case1=solve(slices, 0, n-2, n/3, dp1);
        vector<vector<int>>dp2(n+1,vector<int>(n+1,-1));
        int case2=solve(slices, 1, n-1, n/3, dp2);
        return max(case1, case2);
    }
};