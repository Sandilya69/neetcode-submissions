class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;

        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums[0];
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(nums, mid, p)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

private:
    bool isValid(vector<int>& nums, int threshold, int p) {
        int i = 0, count = 0;
        while (i < nums.size() - 1) {
            if (abs(nums[i] - nums[i + 1]) <= threshold) {
                count++;
                i += 2;
            } else {
                i++;
            }
            if (count == p) return true;
        }
        return false;
    }
};