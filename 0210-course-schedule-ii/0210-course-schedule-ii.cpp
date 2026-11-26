class Solution {
public:
    bool hasCycle(int src, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& path){
        vis[src]=true;
        path[src]=true;
        for(auto& i: adj[src]){
            if(!vis[i]){
                if(hasCycle(i,adj,vis,path)) return true;
            }else if(path[i]){
                return true;
            }
        }
        path[src]=false;
        return false;
    }
    void topo(int src, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& s){
        vis[src]=true;
        for(auto& i:adj[src]){
            if(!vis[i]){
                topo(i,adj,vis,s);
            }
        }
        s.push(src);
    }
    vector<int> findOrder(int n, vector<vector<int>>& graph) {
        vector<vector<int>>adj(n);
        for(auto& i: graph){
            adj[i[1]].push_back(i[0]);
        }
        vector<bool>vis(n,false);
        vector<bool>path(n,false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(hasCycle(i,adj,vis,path)) return {};
            }
        }
        stack<int>s;
        vis.assign(n,false);
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                topo(i,adj,vis,s);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};