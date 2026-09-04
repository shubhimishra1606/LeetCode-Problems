class Solution {
public:
    int maxi(vector<int>& nums, int st, int e){
        int mx=INT_MIN;
        for(int j=st; j<=e; j++){
            mx=max(mx,nums[j]);
        }
        return mx;
    }
    int mini(vector<int>& nums,int st, int e){
        int mn=INT_MAX;
        for(int j=st; j<=e; j++){
            mn=min(mn,nums[j]);
        }
        return mn;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(maxi(nums,0,i)-mini(nums,i,n-1)<=k) return i;
        }
        return -1;
    }
};