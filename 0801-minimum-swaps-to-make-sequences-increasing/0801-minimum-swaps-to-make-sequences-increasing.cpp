class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n=nums1.size();
        vector<vector<int>>dp(n+1, vector<int>(2,0));
        for(int idx=n-1; idx>=1; idx--){
            for(int swapped=1; swapped>=0; swapped--){
                int ans=INT_MAX;
                int prev1=nums1[idx-1], prev2=nums2[idx-1];
                if(swapped) swap(prev1, prev2);
                if(nums1[idx]>prev1 && nums2[idx]>prev2){
                    ans=dp[idx+1][0];
                }
                if(nums1[idx]>prev2 && nums2[idx]>prev1){
                    ans=min(ans, 1+dp[idx+1][1]);
                }
                dp[idx][swapped]=ans;
            }
        }
        return dp[1][0];
    }
};