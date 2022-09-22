class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_set<int> count;
        for (int i = 0; i < n; i ++) count.insert(nums[i]);
        for (int i = 1; i <= n; i ++) {
            if (count.count(i) == 0)
                ans.push_back(i);
        }
        return ans;
    }
};
