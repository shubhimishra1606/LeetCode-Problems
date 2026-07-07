class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0, sum=0;
        string s=to_string(n);
        for(char ch: s){
            if(ch != '0'){
                x=x*10+(ch-'0');
                sum+=(ch-'0');
            }
        }
        return sum*x;
    }
};