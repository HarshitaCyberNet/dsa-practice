class Solution {
public:
    // O(n * 2^n)
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i,
                       vector<vector<int>>& allsubsets) {
        if (i == nums.size()) {
            allsubsets.push_back({ans});
            return;
        }
        // inclusion
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allsubsets);
        // backtrack
        ans.pop_back();
        // exclusion
        getAllSubsets(nums, ans, i + 1, allsubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubsets;
        vector<int> ans;
        getAllSubsets(nums, ans, 0, allsubsets);
        return allsubsets;
    }
};