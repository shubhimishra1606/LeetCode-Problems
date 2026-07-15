class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r=matrix.size(), c=matrix[0].size(), mx=0;
        vector<int>curr(c+1,0);
        vector<int>next(c+1,0);
        for(int i=r-1; i>=0; i--){
            for(int j=c-1; j>=0; j--){
                int right=curr[j+1];
                int down=next[j];
                int diagonal=next[j+1];
                if(matrix[i][j]=='1'){
                    curr[j]=1+min({right, down, diagonal});
                    mx=max(mx,curr[j]);
                }else{
                    curr[j]=0;
                }
            }
            next=curr;
        }
        return mx*mx;
    }
};