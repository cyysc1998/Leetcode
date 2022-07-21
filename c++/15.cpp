class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        // for (auto e: nums)
        //     cout << e << " ";
        // cout << endl;
        if (nums.size() < 3) return {};
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] > 0) break;
            int L = i + 1, R = nums.size() - 1;
            while (L < R) {
                // cout << nums[i] << " " << nums[L] << " " << nums[R] << endl;
                if (nums[i] + nums[L] + nums[R] == 0) {
                    ans.push_back({nums[i], nums[L], nums[R]});
                    if (L < R) {
                        while (L < R && nums[L] == nums[L + 1]) L ++;
                        while (L < R && nums[R] == nums[R - 1]) R --;
                        L ++;
                        R --;
                    }
                }
                else if (nums[i] + nums[L] + nums[R] < 0)
                    L ++;
                else
                    R --;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i ++;
        }
        return ans;
    }
};
