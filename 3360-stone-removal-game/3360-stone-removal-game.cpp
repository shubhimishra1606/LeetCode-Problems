class Solution {
public:
    bool canAliceWin(int n) {
        bool a=true;
        int i=10;
        while(n>=0){
            n-=i;
            i--;
            a=((a==true)?false:true);
        }
        return a==true;
    }
};