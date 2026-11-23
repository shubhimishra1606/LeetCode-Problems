class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!='O') return;
        board[i][j]='.';
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
    void solve(vector<vector<char>>& board) {
        int r=board.size(), c=board[0].size();
        for(int i=0; i<r; i++){
            dfs(board, i, 0);
            dfs(board, i, c-1);
        }
        for(int j=0; j<c; j++){
            dfs(board, 0, j);
            dfs(board, r-1, j);
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                board[i][j]=(board[i][j]=='.')?'O':'X';
            }
        }
    }
};