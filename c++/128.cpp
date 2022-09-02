class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> ht;
        for (auto num: nums) ht.insert(num);

        int ans = 1;
        for (int i = 0; i < nums.size(); i ++) {
            if (ht.count(nums[i] - 1) != 0) continue;
            int cur_num = nums[i] + 1;
            int cur_len = 1;
            while (ht.count(cur_num) != 0) {
                cur_num ++;
                cur_len ++;
            }
            ans = max(ans, cur_len);
        }
        return ans;
    }
};
