class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int>mp;
        int count = 0;
        int res = 0;

        for(int i = 0; i<s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                count = max(mp[s[i]]+1, count);
            }
            mp[s[i]] = i;
            res = max(res, i - count + 1);
        }
        return res;
        
    }
};
