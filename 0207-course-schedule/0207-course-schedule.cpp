class Solution {
public:
    bool hasCycle(int i, int p, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& path){
        vis[i]=true;
        path[i]=true;
        for(auto& n: adj[i]){
            if(!vis[n]){
                if(hasCycle(n,i,adj,vis,path)) return true;
            }else if(path[n]){
                return true;
            }
        }
        path[i]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<bool>vis(numCourses,false);
        vector<bool>path(numCourses,false);
        for(auto& i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(hasCycle(i,-1,adj,vis,path)){
                    return false;
                }
            }
        }
        return true;
    }
};