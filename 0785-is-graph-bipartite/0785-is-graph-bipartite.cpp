class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int src, int c){
        color[src]=c;
        for(auto& n: graph[src]){
            if(color[n]==-1){
                if(!dfs(graph,color,n,1-c)){
                    return false;
                }
            }else{
                if(color[n]==c){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0; i<n; i++){
            if(color[i]==-1){
                if(!dfs(graph,color,i,0)) return false;
            }
        }
        return true;
    }
};