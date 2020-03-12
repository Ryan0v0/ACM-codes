class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for (vector<int> inter : intervals) {
            if (inter[1] < newInterval[0]) {
                ans.push_back(inter);
            }
            /*if (inter[0] > newInterval[1]) {
                ans.push_back(inter);
            }*/
            if (inter[0] >= newInterval[0] && inter[0] <= newInterval[1]) {
                newInterval[1] = max(newInterval[1], inter[1]);
            }
            if (inter[1] >= newInterval[0] && inter[1] <= newInterval[1]) {
                newInterval[0] = min(newInterval[0], inter[0]);
            }
            if (inter[0] < newInterval[0] && inter[1] > newInterval[1]) {
                newInterval[0] = inter[0];
                newInterval[1] = inter[1];
            }
        }
        ans.push_back(newInterval);
        for (vector<int> inter : intervals) {
            if (inter[0] > newInterval[1]) {
                ans.push_back(inter);
            }
        }
        return ans;
    }
};
