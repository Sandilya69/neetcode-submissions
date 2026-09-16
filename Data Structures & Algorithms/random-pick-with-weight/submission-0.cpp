class Solution {
public:
    vector<int> prefix;

    Solution(vector<int>& w) {
        prefix.push_back(0);
        for (int wgt : w) {
            prefix.push_back(prefix.back() + wgt);
        }
    }

    int pickIndex() {
        double target = prefix.back() * ((double) rand() / RAND_MAX);
        int l = 1, r = prefix.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (prefix[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l - 1;
    }
};