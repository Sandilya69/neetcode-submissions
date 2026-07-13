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

    int postIdx;
    int inIdx;

    TreeNode* dfs(vector<int>& postorder, vector<int>& inorder, int limit){

        if(postIdx < 0){
            return NULL;
        }

        if(inorder[inIdx] == limit){
            inIdx--;
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postIdx--]);
        root->right = dfs(postorder, inorder, root->val);
        root->left = dfs(postorder, inorder, limit);

        return root;

       
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        postIdx = postorder.size() - 1;
        inIdx = inorder.size() - 1;

        return dfs(postorder, inorder, numeric_limits<int>::max());
        
    }
};