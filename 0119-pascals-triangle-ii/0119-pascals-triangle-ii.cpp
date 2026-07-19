class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>temp;
        temp.push_back(1);
        for(int i=1; i<=rowIndex; i++){
            vector<int>ans;
            ans.push_back(1);
            if(temp.size()>1){
                for(int j=0; j<temp.size()-1; j++){
                    ans.push_back(temp[j]+temp[j+1]);
                }
            }
            ans.push_back(1);
            temp=ans;
        }
        return temp;
    }
};