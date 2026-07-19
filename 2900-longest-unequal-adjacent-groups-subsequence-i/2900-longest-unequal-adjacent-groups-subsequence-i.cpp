class Solution {
public:
    void solve(vector<string>& words, vector<int>& groups, vector<string>& ans, int i){
        if(i>=words.size()) return;
        if(i==0){ 
            ans.push_back(words[i]);
        }
        else if(groups[i]!=groups[i-1]){
            ans.push_back(words[i]);
        }
        solve(words,groups,ans,i+1);
    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
        solve(words, groups, ans, 0);
        return ans;
    }
};