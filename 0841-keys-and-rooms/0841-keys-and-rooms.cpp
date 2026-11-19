class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int src){
        for(int i=0; i<rooms[src].size(); i++){
            if(!visited[rooms[src][i]]){
                visited[rooms[src][i]]=true;
                dfs(rooms, visited, rooms[src][i]);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        visited[0]=true;
        dfs(rooms,visited,0);
        for(int i=0; i<n; i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};