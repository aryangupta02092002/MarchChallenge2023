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
  void helper(TreeNode* root, int &ans, int n){
    if(!root){
      return;
    }
    if(root->left == NULL && root->right == NULL){
      ans += n*10 + root->val;
    }
    else{
      n = n*10 + root->val;
    }
    helper(root->left, ans, n);
    helper(root->right, ans, n);
  }
    int sumNumbers(TreeNode* root) {
        int ans=0;
      helper(root, ans, 0);
      return ans;
    }
};
