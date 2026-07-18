class Solution {
public:
    bool solve(vector<int>& nums, int target, int i, vector<vector<int>>& dp){
        if(target==0) return true;
        if(i>=nums.size()) return false;
        if(dp[i][target] != -1) return dp[i][target];
        bool take=false;
        if(target>=nums[i]){
            take=solve(nums,target-nums[i],i+1,dp);
        }
        bool notTake=solve(nums,target,i+1,dp);
        return dp[i][target]=take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i: nums){
            sum+=i;
        }
        if(sum%2==1) return false;
        int target=sum/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        return solve(nums,target,0,dp);
    }
};