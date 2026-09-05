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

    bool areSame(TreeNode*root1, TreeNode*root2){
        if(!root1 && !root2){
            return true;
        }
        if(!root1 || !root2) return false;
        if(root1->val!=root2->val)  return false;
        return areSame(root1->left, root2->left) && areSame(root1->right, root2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && subRoot)    return false;
        if(!root && !subRoot)   return true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*tmp = q.front();
            q.pop();
            if(tmp->val==subRoot->val){
                if(areSame(tmp, subRoot)){
                    return true;
                }
            }
            if(tmp->left)   q.push(tmp->left);
            if(tmp->right)  q.push(tmp->right);
        }
        return false;
    }
};
