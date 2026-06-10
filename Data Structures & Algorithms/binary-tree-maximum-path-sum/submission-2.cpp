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
    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;

        int leftMax = dfs(root->left, res);
        int rightMax = dfs(root->right, res);

        leftMax = max(leftMax, 0);
        rightMax = max(rightMax, 0);

        res = max(res, root->val + leftMax + rightMax);

        return root->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        int res = root->val;
        int ans = dfs(root, res);

        return res;
    }
};