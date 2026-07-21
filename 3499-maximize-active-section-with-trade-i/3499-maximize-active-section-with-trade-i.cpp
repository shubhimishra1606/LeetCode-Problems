class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int>zeros;
        int r=0;
        for(char c: s)
            if(c=='0') r++;
            else if(r) zeros.push_back(exchange(r, 0));
        if(r) zeros.push_back(r);
        int maxzeros=0;
        for(int i=1; i<zeros.size(); i++)
            maxzeros=max(maxzeros, zeros[i-1]+zeros[i]);
        return ranges::count(s, '1') + maxzeros;
    }
};