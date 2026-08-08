/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int preOrder(TreeNode*root,int val,int &good){
        if(root==nullptr) return good;
        if(root->val>=val){good++;val=root->val;}
        good=preOrder(root->left,val,good);
        good=preOrder(root->right,val,good);
        return good;
    }
public:
    int goodNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr) return 1;
        int good=0;
        good=preOrder(root,root->val,good);
        return good;

    }
};
