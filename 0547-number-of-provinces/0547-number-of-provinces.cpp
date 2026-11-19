class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int src){
        for(int i=0; i<adj[src].size(); i++){
            if(!visited[adj[src][i]]){
                visited[adj[src][i]]=true;
                dfs(adj,visited,adj[src][i]);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n+1);
        vector<bool>visited(n+1,false);
        visited[0]=true;
        for(int i=0; i<n; i++){
            for(int j=0; j<isConnected[i].size(); j++){
                if(i==j) continue;
                if(isConnected[i][j]==1) adj[i+1].push_back(j+1);
            }
        }
        int count=0;
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                count++;
                visited[i]=true;
                dfs(adj,visited,i);
            }
        }
        return count;
    }
};