#include <vector>
#include <queue>

using namespace std;

class Solution {

private:
    vector<int>ud={1,-1,0,0};
    vector<int>lr={0,0,1,-1};

    bool isValid(int r,int c,vector<vector<bool>>&visited,vector<vector<int>>& grid){
        if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && visited[r][c]==false && grid[r][c]==inf) return true;
        return false;
    }

    void bfs(int r,int c, vector<vector<bool>>&visited,vector<vector<int>>& grid, queue<pair<int,int>>& q){
        for(int i=0;i<4;i++){
            int row=r+ud[i];
            int col=c+lr[i];
            if(isValid(row,col,visited,grid)){
                grid[row][col]=grid[r][c]+1;
                visited[row][col]=true;
                q.push({row,col}); 
            }
        }
    }

public:
    const int inf = 2147483647; 

    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty()) return;

        queue<pair<int,int>>q;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));

        //mark all tresure chests first
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) {
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        } 

        while(!q.empty()){
            pair<int,int> chest=q.front();
            q.pop();
            bfs(chest.first,chest.second,visited,grid,q);
        }
    }

};
