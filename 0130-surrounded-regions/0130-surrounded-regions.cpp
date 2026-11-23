class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size(), c=board[0].size();
        queue<pair<int,int>>q;
        for(int i=0; i<r; i++){
            if(board[i][0]=='O'){ q.push({i,0}); board[i][0]='.';}
            if(board[i][c-1]=='O') {q.push({i,c-1}); board[i][c-1]='.';}
        }
        for(int j=0; j<c; j++){
            if(board[0][j]=='O') {q.push({0,j}); board[0][j]='.';}
            if(board[r-1][j]=='O') {q.push({r-1,j}); board[r-1][j]='.';}
        }
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int nr=i+dr[k], nc=j+dc[k];
                if(nr>=0 && nr<r &&  nc>=0 && nc<c && board[nr][nc]=='O'){
                    board[nr][nc]='.';
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                board[i][j]=(board[i][j]=='.')?'O':'X';
            }
        }
    }
};