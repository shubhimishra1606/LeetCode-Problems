class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            int need=target-nums[i];
            if(mp.count(need) && mp[need]!=i){
                return{mp[need],i};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};