class Solution {
public:
int sayim = 0;
int ara = 0;
    void inorder(TreeNode* root, int k){
        if(root==NULL) return;
        inorder(root->left, k);
        sayim++;
        if(sayim == k){
            ara = root->val;
            return;
        }
        inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ara;
    }
};
