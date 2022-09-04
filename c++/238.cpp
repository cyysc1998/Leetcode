class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int non_zero_prod = 1;
        int num_zero = 0;
        for (auto num: nums) {
            if (num != 0) non_zero_prod *= num;
            else num_zero ++;
        }
        vector<int> ans;
        for (auto num: nums) {
            if (num != 0 && num_zero != 0) ans.push_back(0);
            else if (num != 0 && num_zero == 0) ans.push_back(non_zero_prod / num);
            else if (num == 0 && num_zero == 1) ans.push_back(non_zero_prod);
            else ans.push_back(0);
        }
        return ans;
    }
};
