class Solution {
    public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) {
            return ans;
        }
        string mp[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ans.push_back(""); //important!
        for (int i = 0; i < digits.size(); i++) {
            string chars = mp[digits[i] - '0'];    
            vector<string> tmp;
            for (string str : ans) {
                for (char c : chars) {
                    tmp.push_back(str + c);
                }
            }
            ans = tmp;
        }
        return ans;
    }
};
