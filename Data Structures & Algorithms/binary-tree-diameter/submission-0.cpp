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
    int helper(TreeNode*root){
        if(!root){
            return 0;
        }
        int left,right;
        left = helper(root->left);
        right = helper(root->right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        stack<TreeNode*>st;
        st.push(root);
        int ans = INT_MIN;
        while(!st.empty()){
            TreeNode*tmp = st.top();
            st.pop();
            int diam = 0;
            if(tmp->left)   diam+=helper(tmp->left);
            if(tmp->right)  diam+=helper(tmp->right);
            ans = max(ans, diam);
            if(tmp->left)   st.push(tmp->left);
            if(tmp->right)  st.push(tmp->right);
        }
        return ans;

    }
};
