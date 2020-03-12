class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[30];
        memset(cnt, 0, sizeof(cnt));
        if (s.length() != t.length()) {
            return false;
        }
        for (char ch : s) {
            cnt[ch - 'a']++;
        }
        for (char ch : t) {
            if(!cnt[ch - 'a']) {
                return false;
            }
            cnt[ch - 'a']--;
        }
        return true;
    }
};
