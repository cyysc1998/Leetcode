class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num: nums) sum += num;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<int> V(target + 1);
        for (int i = 1; i < V.size(); i ++)
            V[i] = INT_MIN;
        
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = target; j >= nums[i]; j --)
                V[j] = max(V[j], V[j - nums[i]] + 1);
        }

        return V[target] > 0;

    }   

};
