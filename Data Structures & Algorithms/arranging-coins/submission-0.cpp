class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 1, r = n, res = 0;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long coins = (mid * (mid + 1)) / 2;
            if (coins > n) {
                r = mid - 1;
            } else {
                l = mid + 1;
                res = max(res, mid);
            }
        }

        return res;
    }
};