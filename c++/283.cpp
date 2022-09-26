class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_conut = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] != 0) nums[i - zero_conut] = nums[i];
            else zero_conut ++;
        }
        for (int i = 0; i < zero_conut; i ++)
            nums[nums.size() - i - 1] = 0;
    }
};
