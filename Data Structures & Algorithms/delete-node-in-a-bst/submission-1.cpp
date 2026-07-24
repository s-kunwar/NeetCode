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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        TreeNode* schnode = nullptr;
        TreeNode* currnode = root;
        TreeNode* parentOfSch = nullptr;
        if(root==nullptr) return nullptr;

        while(currnode != nullptr){
            if(currnode->val == key) {
                schnode = currnode;
                break;
            }
            parentOfSch = currnode;
            if(key > currnode->val) currnode = currnode->right;
            else currnode = currnode->left;
        }

        if(schnode==nullptr) return root;
        if(schnode->left==nullptr && schnode->right==nullptr){
            if(schnode==root) return nullptr;
            if(parentOfSch->left==schnode) parentOfSch->left=nullptr;
            else parentOfSch->right=nullptr;
            return root;
        }

        //predecessor
        if(schnode->left!=nullptr){
            TreeNode*parent=schnode;
            TreeNode*pred=schnode->left;
            while(true){
                if (pred->right==nullptr) break;
                else{
                    parent=pred;
                    pred=pred->right;
                }
            }
            schnode->val=pred->val;
            if(parent->left==pred) parent->left=pred->left;
            else parent->right=pred->left;
            return root;
        }
        //successor
        else if(schnode->right!=nullptr){
            TreeNode*parent=schnode;
            TreeNode*pred=schnode->right;
            while(true){
                if (pred->left==nullptr) break;
                else{
                    parent=pred;
                    pred=pred->left;
                }
            }
            schnode->val=pred->val;
            if(parent->right==pred) parent->right=pred->right;
            else parent->left=pred->right;
            return root;
        }   
        else{
            return root;
        }   


    }
};