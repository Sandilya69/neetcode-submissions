class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string answer;for(int i=0;i<nums.size();i++)answer+=nums[i][i]=='0'?'1':'0';return answer;
    }
};
