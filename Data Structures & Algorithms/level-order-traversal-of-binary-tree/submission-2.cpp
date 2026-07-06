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
    void helper(TreeNode* root, vector<vector<int>>& vec, vector<int>& v) {
        if (root == NULL) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr != NULL) {
                v.push_back(curr->val);
            } else if (curr == NULL && q.empty()) {
                vec.push_back(v);
                break;
            } else {
                vec.push_back(v);
                v.clear();
                q.push(NULL);
                continue;
            }
            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);
        }
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        vector<int> v;

        helper(root, vec, v);
        return vec;
    }
};
