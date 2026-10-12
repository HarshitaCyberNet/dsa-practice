
class Solution {
public:
    void printSubsets(vector<int>& nums, vector<int>& combin,
                      vector<vector<int>>& ans, int i) {
        if (i == nums.size()) {
            ans.push_back(combin);
            return;
        }

        // Include
        combin.push_back(nums[i]);
        printSubsets(nums, combin, ans, i + 1);
        combin.pop_back(); // Backtrack

        // Exclude
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[i]) {
            idx++;
        }

        printSubsets(nums, combin, ans, idx);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> combin;
        vector<vector<int>> ans;

        printSubsets(nums, combin, ans, 0);

        return ans;
    }
};