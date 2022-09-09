class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> indices;
        vector<int> ans(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i ++) {
            while (!indices.empty() && temperatures[i] > temperatures[indices.top()]) {
                int t = indices.top();
                ans[t] = i - t;
                indices.pop();
            }
            indices.push(i);
        }
        return ans;
    }
};
