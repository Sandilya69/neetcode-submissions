class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = k - 1, res = INT_MAX;
        while (r < nums.size()) {
            res = min(res, nums[r] - nums[l]);
            l++;
            r++;
        }
        return res;
    }
};