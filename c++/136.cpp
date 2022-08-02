class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int t = 0;
        for (auto num: nums)
            t ^= num;
        return t;
    }
};
