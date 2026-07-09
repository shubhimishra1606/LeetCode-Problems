class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int>vec(n);
        for(int i=1; i<n; i++){
            vec[i]=vec[i-1]+(nums[i]-nums[i-1]>maxDiff);
        }
        vector<bool>ans;
        for(auto &q : queries){
            ans.push_back(vec[q[0]]==vec[q[1]]);
        }
        return ans;
    }
};