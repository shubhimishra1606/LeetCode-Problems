class Solution {
public:
    bool checkDivisibility(int n) {
        int m=n, sum=0, prod=1;
        while(m!=0){
            sum+=(m%10);
            prod*=(m%10);
            m/=10;
        }
        if(n%(sum+prod)==0) return true;
        else return false;
    }
};