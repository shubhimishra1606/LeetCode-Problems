class Solution {
public:
    bool uniformArray(vector<int>& a) {
        int mn=INT_MAX, odd=0;
        for(int x: a){
            mn=min(mn, x);
            if(x%2==1) odd++;
        }
        return mn%2 || odd==0; 
    }
};