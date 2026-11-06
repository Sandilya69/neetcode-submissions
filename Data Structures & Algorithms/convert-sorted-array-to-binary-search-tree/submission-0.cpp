class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int, int)> build = [&](int lo, int hi) -> TreeNode* {
            if (lo > hi) return nullptr;
            int mid = (lo + hi) / 2;
            return new TreeNode(nums[mid], build(lo, mid - 1), build(mid + 1, hi));
        };
        return build(0, nums.size() - 1);
    }
};
