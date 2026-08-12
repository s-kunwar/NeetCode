class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) continue;
                //left
                if(j==0) p++;
                else{
                    if(grid[i][j-1]==0) p++;
                }
                //right
                if(j==grid[0].size()-1) p++;
                else{
                    if(grid[i][j+1]==0) p++;
                }
                //top
                if(i==0)p++;
                else{
                    if(grid[i-1][j]==0) p++;
                }
                //bottom
                if(i==grid.size()-1) p++;
                else{
                    if(grid[i+1][j]==0)p++;
                }
            }
        }
        return p;
    }
};