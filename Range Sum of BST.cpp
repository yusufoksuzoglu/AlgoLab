class Solution {
public:
    int gezinme(TreeNode* root, int low, int high, int &toplam){
        if(root==NULL) return 0;
        if(root->val <= high && root->val >= low){
             toplam+=root->val;
        }     
        gezinme(root->left, low, high, toplam);
        gezinme(root->right, low, high, toplam);
        return toplam;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int toplam = 0;
       return gezinme(root, low, high, toplam);
    }
};
