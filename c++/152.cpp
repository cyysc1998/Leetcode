class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        int max_left = nums[0], max_right = nums[n - 1];
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i ++) {
            left[i] = nums[i - 1] == 0 ? nums[i] : left[i - 1] * nums[i];
            right[n - i - 1] = nums[n - i] == 0 ? nums[n - i - 1] : right[n - i] * nums[n - i - 1];
            max_left = max(max_left, left[i]);
            max_right = max(max_right, right[n - i - 1]);
        }
        return max(max_left, max_right);
    }
};
