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
public:
    void flatten(TreeNode* root) {
        solve(root);
    }
    
    pair<TreeNode*, TreeNode*> solve(TreeNode *root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return {root, root};
        TreeNode *curr = root;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = NULL;
        if(left) {
            pair<TreeNode*, TreeNode*> temp = solve(left);
            curr->right = temp.first;
            curr = temp.second;
        }
        if(right) {
            pair<TreeNode*, TreeNode*> temp = solve(right);
            curr->right = temp.first;
            curr = temp.second;
        }
        return {root, curr};
    }
};
