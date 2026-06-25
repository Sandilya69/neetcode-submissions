class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxsum = nums[0];

        int currsum = 0;

        for(int num: nums){

            if(currsum < 0 ){
                currsum = 0;
            }
            currsum += num;

            maxsum = max(maxsum, currsum);
        }
        return maxsum;
    }
};
