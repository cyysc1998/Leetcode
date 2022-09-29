class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int begin = -1, end = -2;
        int cur_max = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            if (cur_max > nums[i]) end = i;
            cur_max = max(cur_max, nums[i]);
        }
        cur_max = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i --) {
            if (cur_max < nums[i]) begin = i;
            cur_max = min(cur_max, nums[i]);
        }
        return end - begin + 1;
    } 
};
