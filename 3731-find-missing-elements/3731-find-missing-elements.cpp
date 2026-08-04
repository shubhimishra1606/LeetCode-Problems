class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        unordered_set<int>s;
        int mx=*max_element(nums.begin(), nums.end());
        int mn=*min_element(nums.begin(), nums.end());
        for(int i= 0; i<n; i++){
            s.insert(nums[i]);
        }
        for(int i=mn; i<=mx; i++){
            if(s.count(i)) continue;
            else ans.push_back(i);
        }
        return ans;
    }
};