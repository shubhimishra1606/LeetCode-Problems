class Solution {
public:
    void dfs(vector<vector<pair<int,int>>>& adj, vector<int>& dist, int k){
        for(auto& i: adj[k]){
            int v=i.first;
            int wt=i.second;
            if(dist[k]+wt<dist[v]){
                dist[v]=dist[k]+wt;
                dfs(adj,dist,v);
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i: times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        dist[k]=0;
        dfs(adj,dist,k);
        int max_time=0;
        for(int i=1; i<=n; i++){
            if(dist[i]==INT_MAX) return -1;
            max_time=max(max_time,dist[i]);
        }
        return max_time;
    }
};