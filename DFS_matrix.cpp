/*

Using DFS on matrix:
1. Avoid using the general dfs function in this case.
2. If asked to traverse up, down, left and right:
    dfs(i, j){
        _________________
        dfs(i-1, j);
        dfs(i+1, j);
        dfs(i, j-1);
        dfs(i, j+1);
        __________________
    }
    where i and j are coordinates.
3. If matrix values are changing, then it may not always be necessary to use a visited array.

For More: https://leetcode.com/problems/flood-fill/submissions/
          https://leetcode.com/problems/number-of-islands/submissions/

*/

//Sample code 1: Flood Fill

class Solution1 {
public:
    void dfs(int i, int j, int initColor, int Color, vector<vector<int> > &image){
        if(i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != initColor) return;
        image[i][j] = Color;
        dfs(i-1, j, initColor, Color, image);
        dfs(i+1, j, initColor, Color, image);
        dfs(i, j-1, initColor, Color, image);
        dfs(i, j+1, initColor, Color, image);
    }
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int color) {
        int initColor = image[sr][sc];
        if(color != initColor) dfs(sr, sc, initColor, color, image);
        return image;
    }
};

//Sample Code 2: Islands

class Solution2 {
public:
    void dfs(vector<vector<char> > &grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1') return;
        grid[i][j] = '2';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};