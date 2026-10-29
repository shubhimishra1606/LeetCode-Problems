class Solution {
public:
    int solve(string s, int n, int i, vector<int>& dp){
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int ways=solve(s,n,i+1,dp);
        if(i+1<n){
            int dig=stoi(s.substr(i,2));
            if(dig>=10 && dig<=26){
                ways+=solve(s,n,i+2,dp);
            }
        }
        return dp[i]=ways;
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return solve(s,n,0,dp);
    }
};