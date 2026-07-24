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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<TreeNode*>>ans;
        if(root==nullptr) return {};
        if(root->left==nullptr && root->right==nullptr) return {root->val};
        ans.push_back({root});
        int idx=0;
        while(true){
            ans.push_back({});
            for(int i=0;i<ans[idx].size();i++){
                if(ans[idx][i]->right!=nullptr) ans[idx+1].push_back(ans[idx][i]->right);
                if(ans[idx][i]->left!=nullptr) ans[idx+1].push_back(ans[idx][i]->left);
            }
            if(ans[idx+1].empty()) {ans.pop_back();break;}
            idx++;
        }
        vector<int>vals;
        for(int i=0;i<ans.size();i++){
            vals.push_back(ans[i][0]->val);
        }
        return vals;
    }
};
