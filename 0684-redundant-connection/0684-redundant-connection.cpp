class Solution {
public:
    bool bfs(int u, int v, vector<vector<int>>& adj, int n){
        vector<bool>visited(n+1,false);
        queue<int>q;
        visited[u]=true;
        q.push(u);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==v) return true;
            for(auto& i: adj[node]){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
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
            if(bfs(u,v,adj,n)){
                return edge;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};