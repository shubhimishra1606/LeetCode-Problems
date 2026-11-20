class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int value){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size()) return;
        if(image[sr][sc]!=value){
            return;
        }
        image[sr][sc]=color;
        dfs(image,sr+1,sc,color,value);
        dfs(image,sr-1,sc,color,value);
        dfs(image,sr,sc+1,color,value);
        dfs(image,sr,sc-1,color,value);

        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(image,sr,sc,color, image[sr][sc]);
        return image;
    }
};