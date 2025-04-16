class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        if (root1) {
            vector<TreeNode*> stack = {root1};
            while (!stack.empty()) {
                TreeNode* node = stack.back();
                stack.pop_back();
                if (!node->left && !node->right) {
                    leaves1.push_back(node->val);
                } else {
                    if (node->right) stack.push_back(node->right);
                    if (node->left) stack.push_back(node->left);
                }
            }
        }
        if (root2) {
            vector<TreeNode*> stack = {root2};
            while (!stack.empty()) {
                TreeNode* node = stack.back();
                stack.pop_back();
                if (!node->left && !node->right) {
                    leaves2.push_back(node->val);
                } else {
                    if (node->right) stack.push_back(node->right);
                    if (node->left) stack.push_back(node->left);
                }
            }
        }
        return leaves1 == leaves2;
    }
};
