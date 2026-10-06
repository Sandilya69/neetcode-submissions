class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, INT_MAX), nextDp(n + 1, INT_MAX);
        dp[n] = 0;

        for (int m = 1; m <= k; m++) {
            fill(nextDp.begin(), nextDp.end(), INT_MAX);
            for (int i = n - 1; i >= 0; i--) {
                int curSum = 0;
                for (int j = i; j < n - m + 1; j++) {
                    curSum += nums[j];
                    nextDp[i] = min(nextDp[i], max(curSum, dp[j + 1]));
                }
            }
            dp.swap(nextDp);
        }

        return dp[0];
    }
};