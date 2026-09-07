class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i: nums){
            mp[i]++;
        }
        vector<vector<int>>freq(nums.size()+1);
        for(auto& i: mp){
            freq[i.second].push_back(i.first);
        }
        int n=freq.size();
        for(int i=n-1; i>=0; i--){
            if(!freq[i].empty()){
                for(int j=0; j<freq[i].size(); j++){
                    ans.push_back(freq[i][j]);
                    k--;
                }
            }
            if(k==0) return ans;
        }
        return ans;
    }
};