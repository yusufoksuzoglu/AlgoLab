class Solution {
public:
    int maxtop = INT_MIN;
    map<TreeNode*, int> gez;

    int agac(TreeNode* root){
        if(root == NULL) return 0;
        int left = max(agac(root->left), 0);
        int right = max(agac(root->right), 0);
        int toplam = root->val + left + right;
        gez[root] = toplam;
        if(toplam > maxtop) maxtop = toplam;
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        agac(root);
        for(auto &p : gez){
            if(p.second > maxtop){
                maxtop = p.second;
            }
        }
        return maxtop;
    }
};
