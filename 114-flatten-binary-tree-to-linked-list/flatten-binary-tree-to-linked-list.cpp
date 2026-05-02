class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->left);
        flatten(root->right);

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = NULL;
        root->right = left;

        TreeNode* curr = root;
        while (curr->right) {
            curr = curr->right;
        }

        curr->right = right;
    }
};