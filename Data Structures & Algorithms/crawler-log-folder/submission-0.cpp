class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (auto& log : logs) {
            if (log == "./") {
                continue;
            }
            if (log == "../") {
                res = max(0, res - 1);
            } else {
                res++;
            }
        }
        return res;
    }
};