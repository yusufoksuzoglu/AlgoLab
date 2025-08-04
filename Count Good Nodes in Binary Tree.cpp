class Solution {
public:
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int good = 0;
        stack<pair<TreeNode*, int>> stackk;
        stackk.push({root, root->val});
        while (!stackk.empty()) {
            auto [node, maxo] = stackk.top();
            stackk.pop();
            if (node->val >= maxo) {
                good++;
            }
            int maxo2 = max(maxo, node->val);
            if (node->right) stackk.push({node->right, maxo2});
            if (node->left) stackk.push({node->left, maxo2});
        }
        return good;
    }
};
