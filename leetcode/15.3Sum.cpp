class Solution {
private:
    void next(int& x,vector<int>& nums) {
        if (x == 0)
            return;
        while (x < nums.size() && nums[x] == nums[x-1])
            x++;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); next(++i,nums)) {
            for (int j = i + 1, k = nums.size() - 1; j < nums.size(); next(++j,nums)) {
                while (k > j && nums[k] > -nums[i] - nums[j])
                    k--;
                if (k > j && nums[k] == -nums[i] - nums[j])
                    ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return ans;
    }
};
