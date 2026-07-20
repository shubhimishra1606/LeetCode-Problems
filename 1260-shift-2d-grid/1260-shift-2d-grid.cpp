class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size(), c=grid[0].size();
        for(int a=0; a<k; a++){
            int temp=grid[r-1][c-1];
            for(int i=r-1; i>=0; i--){
                for(int j=c-1; j>=0; j--){
                    if(i==0 && j==0){
                        continue;
                    }
                    if(j==0){
                        grid[i][j]=grid[i-1][c-1];
                    }
                    else{
                        grid[i][j]=grid[i][j-1];
                    }
                }
            }
            grid[0][0]=temp;
        }
        return grid;
    }
};