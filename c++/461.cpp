class Solution {
public:

    int low_bit(int n) {
        return n & -n;
    }

    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        int ans = 0;
        while (diff != 0) {
            int t = low_bit(diff);
            ans ++;
            diff -= t;
        }
        return ans;
    }
};
