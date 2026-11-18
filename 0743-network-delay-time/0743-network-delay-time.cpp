class Solution {
public:
    void dijkstra(vector<vector<pair<int,int>>>& adj, vector<int>& dist, int u){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,u});
        while(!pq.empty()){
            auto [currTime, node]=pq.top();
            pq.pop();
            if(currTime>dist[node]) continue;
            for(auto& i: adj[node]){
                int v=i.first;
                int w=i.second;
                if(currTime+w<dist[v]){
                    dist[v]=currTime+w;
                    pq.push({dist[v],v});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        for(auto& i: times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        dijkstra(adj,dist,k);
        int mx=0;
        for(int i=1; i<=n; i++){
            if(dist[i]==INT_MAX) return -1;
            mx=max(mx,dist[i]);
        }
        return mx;
    }
};