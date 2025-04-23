class Solution {
public:

    void dfs(  vector<vector<int>>& image, int sr, int sc, int color, int start_color ){

        if (!(sr < image.size() 
                && sr >= 0 
                && sc < image[sr].size() 
                && sc >= 0) 
            || image[sr][sc] != start_color  
            || image[sr][sc] == color  ){
            return;
        }

        image[sr][sc] = color;

        dfs(image, sr+1, sc, color, start_color);
        dfs(image, sr-1, sc, color, start_color);
        dfs(image, sr, sc+1, color, start_color);
        dfs(image, sr, sc-1, color, start_color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};
