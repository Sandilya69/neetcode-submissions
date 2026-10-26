class Solution {
   public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 0, high = *max_element(candies.begin(), candies.end());
        while (low < high) {
            int middle = (low + high + 1) / 2;
            long long portions = 0;
            for (int x : candies) portions += x / middle;
            if (portions >= k)
                low = middle;
            else
                high = middle - 1;
        }
        return low;
    }
};
