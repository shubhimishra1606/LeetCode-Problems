class Solution {
public:
    bool isDiv(int n, int t){
        int pro=1;
        while(n>0){
            pro*=(n%10);
            n/=10;
        }
        return pro%t==0;
    }
    int smallestNumber(int n, int t) {
        for(int i=0; i<10; i++){
            int pro=n;
            if(isDiv(pro,t)) return n;
            else n++;
        }
        return -1;
    }
};