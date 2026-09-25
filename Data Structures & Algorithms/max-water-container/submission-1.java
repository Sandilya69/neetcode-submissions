class Solution {
    public int maxArea(int[] heights) {
        int left = 0;
        int right = heights.length -1;
        int area = 0;
        int width = 0;
        int res = 0;

        while(left < right){
            width = right - left;
            int height = Math.min(heights[left],heights[right]);
            area = width * height;
            res = Math.max(res, area);
            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return res;
        
    }
}
