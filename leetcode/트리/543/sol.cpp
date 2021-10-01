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
private : 
    int length = 0;    
public:
    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return -1;
        }
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        this->length = max(this->length, left + right + 2);
        
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);        
        return length;
    }
};