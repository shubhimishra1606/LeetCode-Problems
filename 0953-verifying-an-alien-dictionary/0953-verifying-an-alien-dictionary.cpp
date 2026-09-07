class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string> temp=words;
        unordered_map<char,int>mp;
        int j=1, n=words.size();
        for(char i: order){
            mp[i]=j++;
        }
        sort(temp.begin(), temp.end(), [&](const string &a, const string &b){
            int len=min(a.length(), b.length());
            for(int i=0; i<len; i++){
                if(a[i] != b[i]) return mp[a[i]]<mp[b[i]];
            }
            return a.length()<b.length();
        });
        return temp==words;
    }
};