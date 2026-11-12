class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        vector<int> res = nums;

        auto cmp = [&](int a, int b) {
            if (res[a] != res[b]) return res[a] > res[b];
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> minHeap(cmp);

        for (int i = 0; i < n; i++) {
            minHeap.push(i);
        }

        for (int _ = 0; _ < k; _++) {
            int i = minHeap.top();
            minHeap.pop();
            res[i] *= multiplier;
            minHeap.push(i);
        }

        return res;
    }
};