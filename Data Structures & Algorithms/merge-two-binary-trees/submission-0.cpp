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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        stack<pair<TreeNode*, TreeNode*>> stk;
        stk.push({root1, root2});

        while (!stk.empty()) {
            auto [node1, node2] = stk.top();
            stk.pop();

            if (!node2) continue;

            node1->val += node2->val;

            if (!node1->left) {
                node1->left = node2->left;
            } else {
                stk.push({node1->left, node2->left});
            }

            if (!node1->right) {
                node1->right = node2->right;
            } else {
                stk.push({node1->right, node2->right});
            }
        }

        return root1;
    }
};