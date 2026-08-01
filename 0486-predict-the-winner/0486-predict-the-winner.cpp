class Solution {
public:
    int solve(vector<int>& nums, int st, int end, vector<vector<int>>& dp){
        if(st==end) return nums[st];
        if(dp[st][end]!=-1) return dp[st][end];
        int pickLeft=nums[st]-solve(nums,st+1,end,dp);
        int pickRight=nums[end]-solve(nums,st,end-1,dp);
        return dp[st][end]=max(pickLeft,pickRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        int st=0, end=nums.size()-1, n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,st,end,dp)>=0;
    }
};