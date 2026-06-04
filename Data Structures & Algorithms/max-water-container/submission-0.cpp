class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int start = 0;
        int end = heights.size() - 1;
        int maxArea = 0;

        while (start != end) {
            maxArea = max(maxArea, min(heights[start], heights[end]) * (end - start));
            if (heights[start] > heights[end]) {
                end--;
            } else {
                start++;
            }
        }
        return maxArea;
    }
};
