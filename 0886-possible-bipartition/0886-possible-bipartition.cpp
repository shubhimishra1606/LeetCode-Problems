class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>color(n+1,-1);
        vector<vector<int>>adj(n+1);
        for(auto& i: dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=1; i<=n; i++){
            if(color[i]!=-1) continue;
            queue<pair<int,int>>q;
            q.push({i,0});
            color[i]=0;
            while(!q.empty()){
                int node=q.front().first, c=q.front().second;
                q.pop();
                for(auto& j: adj[node]){
                    if(color[j]==-1){
                        color[j]=1-c;
                        q.push({j,1-c});
                    }else{
                        if(color[j]==c) return false;
                    }
                }
            }
        }
        return true;
    }
};