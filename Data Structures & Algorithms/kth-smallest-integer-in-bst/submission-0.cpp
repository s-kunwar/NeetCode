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
    stack<TreeNode*> extendStack(TreeNode*root,stack <TreeNode*>&st){
        if(root==nullptr) return st;
        st=extendStack(root->right,st);
        st.push(root);
        st=extendStack(root->left,st);
        return st;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        st=extendStack(root,st);
        int cnt=0;
        TreeNode* ans=new TreeNode;
        ans->val=0;
        ans->left=nullptr;
        ans->right=nullptr;
        while(!st.empty()){
            if(cnt==k) break;
            ans=st.top();
            st.pop();
            cnt++;
        }
        return ans->val;
    }
};
