class Solution {
public:
    bool dfs(int u, int v, vector<vector<int>>& adj, vector<bool>& visited){
        if(u==v) return true;
        visited[u]=true;
        for(auto& i: adj[u]){
            if(!visited[i]){
                if(dfs(i,v,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(auto& edge: edges){
            int u=edge[0], v=edge[1];
            vector<bool>visited(n+1,false);
            if(dfs(u,v,adj,visited)){
                return edge;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};