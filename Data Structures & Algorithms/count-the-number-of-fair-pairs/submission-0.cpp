class Solution {
   public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long answer = 0;
        for (int pass = 0; pass < 2; pass++) {
            long long limit = pass == 0 ? upper : (long long)lower - 1, total = 0;
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                if ((long long)nums[left] + nums[right] <= limit) {
                    total += right - left;
                    left++;
                } else
                    right--;
            }
            answer += pass == 0 ? total : -total;
        }
        return answer;
    }
};
