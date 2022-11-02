class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long cur_sum = 0;
        long long all_sum = 0;
        int cur_idx = 0;
        long long m = n;
        vector<int> digits;
        
        while (m != 0) {
            digits.push_back(m % 10);
            m /= 10;
        }
        reverse(digits.begin(), digits.end());
        
        for (int i = 0; i < digits.size(); i ++)
            all_sum += digits[i];
        
        for (cur_idx = 0; cur_idx < digits.size(); cur_idx ++) {
            cur_sum += digits[cur_idx];
            if (cur_sum >= target) {
                cur_sum -= digits[cur_idx];
                break;
            }
        }
        
        if (all_sum <= target)
            return 0;
        
        
        long long last = 0;
        int p = 0;
        for (int i = digits.size() - 1; i >= cur_idx; i --) {
            last += digits[i] * pow(10, p);
            p ++;
        }
        
        return pow(10, digits.size() - cur_idx) - last;
        
       
        
    }
};
