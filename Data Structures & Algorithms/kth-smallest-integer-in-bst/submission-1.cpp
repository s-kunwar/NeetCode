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
    void extendStack(TreeNode*root,stack <TreeNode*>&st){
        if(root==nullptr) return;
        extendStack(root->right,st);
        st.push(root);
        extendStack(root->left,st);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        extendStack(root,st);
        int cnt=0;
        
        while(!st.empty()){
            cnt++;
            if(cnt==k) return st.top()->val;
            else st.pop();
        }
    }
};
