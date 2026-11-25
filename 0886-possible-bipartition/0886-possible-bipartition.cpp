class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& color, int src, int c){
        color[src]=c;
        for(auto& i: adj[src]){
            if(color[i]==-1){
                if(!dfs(adj,color,i,1-c)) return false;
            }
            else{
                if(color[i]==c) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto& i: dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>color(n+1,-1);
        for(int i=1; i<=n; i++){
            if(color[i]==-1){
                if(!dfs(adj,color,i,0)) return false;
            }
        }
        return true;
    }
};