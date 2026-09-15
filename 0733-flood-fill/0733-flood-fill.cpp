class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orignal = image[sr][sc];
        
        if(orignal == color)
        return image;
        dfs(image,sr,sc,orignal,color);
        return image;
    }
    private:
    void dfs (vector<vector<int>>& image,int row,int col,int orignal,int color){
        if(row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || image[row][col] != orignal)
        return;

        image[row][col] = color;

        dfs(image,row - 1,col,orignal,color);
        dfs(image,row + 1,col,orignal,color);
        dfs(image,row,col-1,orignal,color);
        dfs(image,row,col+1,orignal,color);
    }
};