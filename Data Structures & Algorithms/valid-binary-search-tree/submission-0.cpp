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

    bool helper(TreeNode*root, int min, int maks){
        if(!root)   return true;
        if(!(root->val>min && root->val<maks)){
            return false;
        }
        return helper(root->left, min, root->val) && helper(root->right, root->val, maks);
    }

    bool isValidBST(TreeNode* root) {
        if(!root)   return true;
        return helper(root, INT_MIN, INT_MAX);
    }
};
