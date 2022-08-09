class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = b_search(nums, 0, nums.size() - 1, target);
        if (nums[ans] == target) return ans;
        else return -1;
    }

    int b_search(vector<int>& nums, int l, int r, int target) {
        if (l >= r) return l;
        int mid = l + r >> 1;
        int b_i = l, b_j = r;
        int de_i = l, de_j = r;

        if (nums[mid] > nums[0]) b_j = mid, de_i = mid + 1;
        else b_i = mid + 1, de_j = mid;

        int ans = search(nums, b_i, b_j, target);
        if (nums[ans] != target) return b_search(nums, de_i, de_j, target);
        else return ans;
    }

    int search(vector<int>& nums, int l, int r, int target) {
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }

};
