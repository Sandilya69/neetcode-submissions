class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for (int x : nums) target |= x;
        vector<int> values(1 << nums.size());
        int size = 1;
        for (int x : nums) {
            for (int i = 0; i < size; i++) values[size+i] = values[i] | x;
            size *= 2;
        }
        int answer = 0;
        for (int i = 1; i < size; i++) if (values[i] == target) answer++;
        return answer;
    }
};
