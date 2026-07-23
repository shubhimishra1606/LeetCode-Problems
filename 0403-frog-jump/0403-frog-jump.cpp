class Solution {
public:
    bool solve(vector<int>& nums, int idx, int jump, vector<vector<int>>& dp){
        if(idx==nums.size()-1) return true;
        if(dp[idx][jump]!=-1) return dp[idx][jump];
        bool k, kminus, kplus;
        for(int i=idx+1; i<nums.size(); i++){
            if(nums[i]==nums[idx]+jump){
                k=solve(nums,i,jump,dp);
            }
            if(nums[i]==nums[idx]+jump-1){
                
                kminus=solve(nums,i,jump-1,dp);

            }
            if(nums[i]==nums[idx]+jump+1){
                kplus=solve(nums,i,jump+1,dp);
            }
            if(k||kminus||kplus) return dp[idx][jump]=true;
        }

        return dp[idx][jump]=false;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]>1) return false;
        vector<vector<int>>dp(stones.size()+1,vector<int>(stones.size()+1,-1));
        return solve(stones,1,1,dp);
    }
};