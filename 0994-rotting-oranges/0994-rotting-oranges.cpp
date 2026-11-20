class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>>visited(grid.size(), vector<bool>(grid[0].size(), false));
        int ans=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int t=q.front().second;
            q.pop();
            ans=max(ans,t);
            if(i-1>=0 && !visited[i-1][j] && grid[i-1][j]==1){
                q.push({{i-1,j},t+1});
                visited[i-1][j]=true;
            }
            if(i+1<grid.size() && !visited[i+1][j] && grid[i+1][j]==1){
                q.push({{i+1,j},t+1});
                visited[i+1][j]=true;
            }
            if(j-1>=0 && !visited[i][j-1] && grid[i][j-1]==1){
                q.push({{i,j-1},t+1});
                visited[i][j-1]=true;
            }
            if(j+1<grid[0].size() && !visited[i][j+1] && grid[i][j+1]==1){
                q.push({{i,j+1},t+1});
                visited[i][j+1]=true;
            }
        }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1 && visited[i][j]==false) return -1;
            }
        }
        return ans;
    }
};