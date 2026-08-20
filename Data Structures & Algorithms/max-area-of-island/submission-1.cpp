class Solution {
private:
    // Direction vectors for moving Up, Down, Left, Right
    vector<int>dr= {-1, 1, 0, 0};
    vector<int>dc= {0, 0, -1, 1};

    bool isValid(int r, int c, int rows, int cols, const vector<vector<int>>& grid, const      vector<vector<bool>>& visited) {
        return (r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c] == 1 && !visited[r][c]);
    }

    int dfs(int r, int c, const vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();
        visited[r][c] = true;
        int area=1;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (isValid(nr, nc, rows, cols, grid, visited)){area+=dfs(nr, nc, grid, visited);}
        }

        return area;
    }

public:

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        vector<vector<bool>> visited (grid.size(),vector<bool>(grid[0].size(),false));
        int sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if( isValid(i,j,grid.size(),grid[0].size(),grid,visited) ){sum=max(sum,dfs(i,j,grid,visited));}
            }
        }

        return sum;

    }


};
