class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>last(26,0);
        vector<int>occ(26,false);
        string ans="";
        for(int i=0; i<s.length(); i++){
            last[s[i]-'a']=i;
        }
        for(int i=0; i<s.length(); i++){
            char ch=s[i];
            if(occ[ch-'a']) continue;
            while(!ans.empty() && ans.back()>ch && last[ans.back()-'a']>i){
                occ[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(ch);
            occ[ch-'a']=true;
        }
        return ans;
    }
};