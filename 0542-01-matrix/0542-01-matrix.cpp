class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size();
        vector<vector<int>>ans(r, vector<int>(c,-1));
        queue<pair<int,int>>q;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(mat[i][j]==0){ 
                    ans[i][j]=0; 
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i-1>=0 && ans[i-1][j]==-1){
                ans[i-1][j]=ans[i][j]+1;
                q.push({i-1, j});
            }
            if(i+1<r && ans[i+1][j]==-1){
                ans[i+1][j]=ans[i][j]+1;
                q.push({i+1, j});
            }
            if(j-1>=0 && ans[i][j-1]==-1){
                ans[i][j-1]=ans[i][j]+1;
                q.push({i, j-1});
            }
            if(j+1<c && ans[i][j+1]==-1){
                ans[i][j+1]=ans[i][j]+1;
                q.push({i, j+1});
            }
        }
        return ans;
    }
};