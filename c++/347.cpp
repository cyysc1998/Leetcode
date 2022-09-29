class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> queue;

        for (auto num: nums)
            count[num] ++;
    
        for (auto& c: count) {
            if (queue.size() < k)
                queue.push(c);
            else if (queue.top().second < c.second) {
                queue.pop();
                queue.push(c);
            }
        }
        vector<int> topk;
        while (k --) {
            topk.push_back(queue.top().first);
            queue.pop();
        }
        return topk;
    }
};
