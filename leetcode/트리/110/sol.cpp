class Solution {
public:
    int check(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }
        
        int left = check(node->left);
        int right = check(node->right);
        
        if(left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        
        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};