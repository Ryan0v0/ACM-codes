class Solution {
private:
    string mp[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void dfs(int x, string digits, vector<string>& ans, string& cur) {
        if (x == digits.length()) {
            ans.push_back(cur);
            return;
        }
        string chars = mp[digits[x] - '0'];
        for (char c : chars) {
            cur = cur + c;
            dfs(x + 1, digits, ans, cur);
            cur.pop_back();
        }
    }        
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) {
            return ans;
        }
        string cur = "";
        dfs(0, digits, ans, cur); // 不能直接写""
        return ans;
    }
};
