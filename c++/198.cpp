class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> money(nums.size() + 1);
        money[1] = nums[0];
        for (int i = 1; i < nums.size(); i ++)
            money[i + 1] = max(money[i], nums[i] + money[i - 1]);
        return money[nums.size()];
    }
};
