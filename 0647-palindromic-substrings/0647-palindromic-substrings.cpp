class Solution {
public:
    bool isPalindrome(string s, int st, int end){
        while(st<=end){
            if(s[st]!=s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.length(), count=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalindrome(s,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};