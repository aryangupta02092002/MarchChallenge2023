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
    bool helper(TreeNode *tmpLeft, TreeNode *tmpRight){
        if(tmpLeft == NULL || tmpRight == NULL){
            return tmpLeft == tmpRight;
        }
        if(tmpLeft->val != tmpRight->val)
            return false;
        return helper(tmpLeft->left, tmpRight->right) && helper(tmpLeft->right, tmpRight->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root == NULL || helper(root->left, root->right);
    }
};
