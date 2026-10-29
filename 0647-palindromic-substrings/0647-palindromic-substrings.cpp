class Solution {
public:
    int palindrome(string s, int st, int end){
        int count=0;
        while(st>=0 && end<=s.length()-1 && s[st]==s[end]){
            count++;
            st--;
            end++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n=s.length(), count=0;
        for(int i=0; i<n; i++){
            count+=palindrome(s,i,i);
            count+=palindrome(s,i,i+1);
        }
        return count;
    }
};