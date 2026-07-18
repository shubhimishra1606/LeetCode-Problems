class Solution {
public:
    bool solve(vector<vector<int>>& grid, int r, int c){
        int row=grid.size(), col=grid[0].size();
        if(r>=row || r<0 || c>=col || c<0) return false;
        if(grid[r][c]==1) return true;
        grid[r][c]=1;
        bool up=solve(grid, r-1, c);
        bool down=solve(grid, r+1, c);
        bool right=solve(grid, r, c+1);
        bool left=solve(grid, r, c-1);
        return up && down && right && left;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size(), count=0;
        for(int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                if(grid[i][j]==0){
                    if(solve(grid,i,j)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};