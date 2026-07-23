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
public:
    int height(TreeNode*root){
        if(root==nullptr) return 0;
        int lh=height(root->left);
        int rh=height(root->right);

        if (lh>rh){
            return 1+lh;
        }
        else{
            return 1+rh;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        int ans=max((lh+rh),diameterOfBinaryTree(root->left));
        ans=max(ans,diameterOfBinaryTree(root->right));
        return ans;
    }
};
