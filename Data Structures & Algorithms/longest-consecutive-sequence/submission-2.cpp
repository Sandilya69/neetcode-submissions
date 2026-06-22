class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 1;
        int longest = 1;

        if(nums.empty()) return 0;


        for(int i  = 1; i<n; i++){

            if(nums[i-1] == nums[i]){
                continue;
            }
            else if(nums[i] == nums[i-1]+1){
                count++;
            }
            else{
                longest = max(count, longest);
                count = 1;
            }
        }
        return max(longest, count);
        
    }
};
