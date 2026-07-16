class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        for(auto& i: nums){
            mx=max(mx,i);
            i=gcd(mx,i);
        }
        sort(nums.begin(), nums.end());
        long long ans=0;
        for(int i=0, j=nums.size()-1; i<j; i++,j--){
            ans+=gcd(nums[i],nums[j]);
        }
        return ans;
    }
};