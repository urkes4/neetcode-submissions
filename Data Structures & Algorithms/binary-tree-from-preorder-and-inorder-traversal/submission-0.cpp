class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int l, int d, int& preIndex) {
        
        if (l > d)
            return nullptr;

        int root = preorder[preIndex++];

        int index = l;
        while (index <= d && inorder[index] != root) {
            index++;
        }

        TreeNode* tmp = new TreeNode(root);

        // levo podstablo
        tmp->left = helper(preorder, inorder, l, index - 1, preIndex);

        // desno podstablo
        tmp->right = helper(preorder, inorder, index + 1, d, preIndex);

        return tmp;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;

        int preIndex = 0;

        return helper(preorder, inorder,
                      0, inorder.size() - 1, preIndex);
    }
};