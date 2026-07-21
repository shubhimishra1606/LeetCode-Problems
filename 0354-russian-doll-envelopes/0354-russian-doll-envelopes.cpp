class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(), envelopes.end(),[](vector<int>& a, vector<int>& b){
            if(a[0]==b[0]) return a[1]>b[1];
            else return a[0]<b[0];
        });
        for(int i=0; i<n; i++){
            cout<<envelopes[i][0]<<" "<<envelopes[i][1]<<endl;
        }
        vector<int>ans;
        ans.push_back(envelopes[0][1]);
        for(int i=0; i<n; i++){
            if(envelopes[i][1]>ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                int idx=lower_bound(ans.begin(), ans.end(), envelopes[i][1])-ans.begin();
                ans[idx]=envelopes[i][1];
            }
        }
        return ans.size();
    }
};