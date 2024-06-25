
class Solution {
public:
    int val = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if (root->right) bstToGst(root->right);
        val = root->val = val + root->val;
        if (root->left) bstToGst(root->left);
        return root;
    }
};