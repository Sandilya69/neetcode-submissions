class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while (low<high) { int mid=low+(high-low)/2; long long needed=0;
            for (int x:nums) needed+=(x-1)/mid;
            if (needed<=maxOperations) high=mid; else low=mid+1;
        }
        return low;
    }
};
