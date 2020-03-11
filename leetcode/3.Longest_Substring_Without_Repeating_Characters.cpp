class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int> mp;
        int start = -1;
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            if (mp.count(s[i]) != 0) {
                start = max(start, mp[s[i]]);
            }
            mp[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }
};
