class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        threshold *= k;
        int res = 0, curSum = 0;

        for (int R = 0; R < arr.size(); R++) {
            curSum += arr[R];
            if (R >= k - 1) {
                if (curSum >= threshold) {
                    res++;
                }
                curSum -= arr[R - k + 1];
            }
        }
        return res;
    }
};
