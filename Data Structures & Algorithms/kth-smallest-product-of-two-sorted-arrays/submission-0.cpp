class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size(), n2 = nums2.size();
        int pos1 = 0; // first non-negative in nums1
        while (pos1 < n1 && nums1[pos1] < 0) {
            pos1++;
        }
        int pos2 = 0; // first non-negative in nums2
        while (pos2 < n2 && nums2[pos2] < 0) {
            pos2++;
        }

        long long left = -10000000000LL, right = 10000000000LL;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (count(nums1, nums2, pos1, pos2, n1, n2, mid) < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

private:
    long long count(const vector<int>& nums1, const vector<int>& nums2,
                    int pos1, int pos2, int n1, int n2,
                    long long prod) {
        long long cnt = 0;

        // negative * negative -> positive
        int i = 0, j = pos2 - 1;
        while (i < pos1 && j >= 0) {
            if ((long long)nums1[i] * nums2[j] > prod) {
                i++;
            } else {
                cnt += (pos1 - i);
                j--;
            }
        }

        // positive * positive -> positive
        i = pos1; j = n2 - 1;
        while (i < n1 && j >= pos2) {
            if ((long long)nums1[i] * nums2[j] > prod) {
                j--;
            } else {
                cnt += (j - pos2 + 1);
                i++;
            }
        }

        // negative * positive -> negative
        i = 0; j = pos2;
        while (i < pos1 && j < n2) {
            if ((long long)nums1[i] * nums2[j] > prod) {
                j++;
            } else {
                cnt += (n2 - j);
                i++;
            }
        }

        // positive * negative -> negative
        i = pos1; j = 0;
        while (i < n1 && j < pos2) {
            if ((long long)nums1[i] * nums2[j] > prod) {
                i++;
            } else {
                cnt += (n1 - i);
                j++;
            }
        }

        return cnt;
    }
};