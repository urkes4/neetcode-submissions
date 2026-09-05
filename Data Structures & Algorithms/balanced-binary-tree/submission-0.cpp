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
    int helper(TreeNode*root, bool& balanced){
        if(!root)   return 0;
        int left, right;
        left = helper(root->left, balanced);
        right = helper(root->right, balanced);
        if(abs(left-right)>1){
            balanced = false;
            return 0;
        }
        return 1+max(helper(root->left, balanced), helper(root->right, balanced));
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        helper(root, ans);
        return ans;
    }
};
