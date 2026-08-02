class Solution {
public:
    int solve(vector<int>& nums, int i, int d, unordered_map<int,int> dp[]){
        if(i<0) return 0;
        if(dp[i].count(d)) return dp[i][d];
        int ans=0;
        for(int j=i-1; j>=0; j--){
            if(nums[i]-nums[j]==d){
                ans=max(ans, 1+solve(nums,j,d,dp));
            }
        }
        return dp[i][d]=ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int ans=INT_MIN;
        unordered_map<int,int>dp[n+1];
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans=max(ans,2+solve(nums,i,nums[j]-nums[i],dp));
            }
        }
        return ans;
    }
};