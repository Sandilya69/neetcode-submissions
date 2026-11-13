class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        for (int t = 0; t < k; t++) {
            int maxIdx = 0;
            for (int i = 1; i < gifts.size(); i++) {
                if (gifts[i] > gifts[maxIdx]) {
                    maxIdx = i;
                }
            }
            gifts[maxIdx] = floor(sqrt(gifts[maxIdx]));
        }

        long long sum = 0;
        for (int g : gifts) sum += g;
        return sum;
    }
};