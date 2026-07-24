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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<TreeNode*>>ans;
        if(root==nullptr)return {};
        ans.push_back({root});
        int idx=0;
        while(true){
            if(ans[idx].size()>=1) ans.push_back({});
            else break
            for(auto i:ans[idx]){
                if(i->left!=nullptr) ans[idx+1].push_back(i->left);
                if(i->right!=nullptr) ans[idx+1].push_back(i->right);
            }
            if(ans[idx+1].empty()) {ans.pop_back();break;}
            idx++;
        }
        vector<vector<int>>ans_val;
        for(int i=0;i<ans.size();i++){
            ans_val.push_back({ans[i][0]->val});
            for(int j=1;j<ans[i].size();j++){
                ans_val[i].push_back(ans[i][j]->val);
            }
        }
        return ans_val;
    }
};
