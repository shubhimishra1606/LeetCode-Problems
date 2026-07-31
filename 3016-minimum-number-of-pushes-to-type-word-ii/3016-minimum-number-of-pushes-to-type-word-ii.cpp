class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        vector<int>freq(26,0);
        for(int i=0; i<n; i++){
            freq[word[i]-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        int j=0, count=0;
        for(int i=0; i<26; i++){
            if(i%8==0) j++;
            count+=(freq[i]*j);
        }
        return count;
    }
};