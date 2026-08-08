/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    
    int isSame(vector<vector<int>>& grid,int rs,int re,int cs,int ce){
        int iniVal=grid[rs][cs];
        for(int r=rs;r<=re;r++){
            for(int c=cs;c<=ce;c++){
                if (grid[r][c]!=iniVal) return -1;
            }
        }
        return iniVal;
    }

    Node* breakGrid(vector<vector<int>>& grid,int rs,int re,int cs,int ce) {
        int rootVal=isSame(grid,rs,re,cs,ce);
        Node*root=new Node;
        if(rootVal>=0){
            (rootVal==0)? root->val=false:root->val=true;
            root->isLeaf=true;
        }
        else{
            root->val=true;
            root->isLeaf=false;
            root->topLeft=breakGrid(grid,rs,(rs+re)/2,cs,(cs+ce)/2);
            root->topRight=breakGrid(grid,rs,(rs+re)/2,(cs+ce+2)/2,ce);
            root->bottomLeft=breakGrid(grid,(rs+re+2)/2,re,cs,(cs+ce)/2);
            root->bottomRight=breakGrid(grid,(rs+re+2)/2,re,(cs+ce+2)/2,ce);
        }
        return root;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        int cols=grid.size(),rows=grid.size();
        return breakGrid(grid,0,rows-1,0,cols-1);
    }

};





