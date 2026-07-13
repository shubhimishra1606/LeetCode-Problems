class Solution {
public:
    void solve(int low, int high, vector<int>& ans, int i){
        if(i>high) return;
        if(i>=low){
            ans.push_back(i);
        }
        int last=i%10;
        if(last<9){
            int next=(i*10)+(last+1);
            solve(low,high,ans,next);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1; i<9; i++){
            solve(low, high, ans, i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};