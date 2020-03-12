class Solution {
private:
    void dfs(vector<string>& ans, string cur, int l, int r, int n) {
        if (cur.length() == 2 * n) {
            ans.push_back(cur);
            return;
        } 
        if (l < n) {
            dfs(ans, cur + "(", l + 1, r, n);
        }
        if (r < l) {
            dfs(ans, cur + ")", l, r + 1, n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, "", 0, 0, n);
        return ans;
    }
};
