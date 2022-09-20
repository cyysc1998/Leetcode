class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, pre = 0;
        unordered_map<int, int> tb;
        tb[0] = 1;

        for (auto num: nums) {
            pre += num;
            ans += tb[pre - k];
            tb[pre] ++;
        }
        
        return ans;
    }
};
