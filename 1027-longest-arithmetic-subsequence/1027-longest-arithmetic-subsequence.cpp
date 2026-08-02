class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int ans=0;
        unordered_map<int,int>dp[n+1];
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int d=nums[i]-nums[j];
                int cnt=1;
                if(dp[j].count(d)){
                    cnt=dp[j][d];
                }
                dp[i][d]=1+cnt;
                ans=max(ans, dp[i][d]);
            }
        }
        return ans;
    }
};