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

    int maxsum = INT_MIN;

    int path(TreeNode* root){

        if(root == NULL){
            return 0;
        }

        int l = max(path(root->left), 0);
        int r = max(path(root->right), 0);

        int new_sum = root->val+l+r;
        maxsum = max(maxsum, new_sum);

        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {

        path(root);
        return maxsum;

    }
};
