class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>ans(arr.size());
        vector<int>temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        int j=1;
        for(int i=0; i<arr.size(); i++){
            mp[temp[i]]=j;
            if(i<arr.size()-1 && temp[i+1]>temp[i]){
                j++;
            }
        }
        for(int i=0; i<arr.size(); i++){
            ans[i]=mp[arr[i]];
        }
        return ans;
    }
};