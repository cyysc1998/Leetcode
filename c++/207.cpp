class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        unordered_map<int, vector<int>> post_class;
        vector<int> pre_class(numCourses);

        for (auto& pair: prerequisites) {
            auto pre = pair[0], post = pair[1];
            post_class[pre].push_back(post);
            pre_class[post] ++;
        }

        for (int i = 0; i < numCourses; i ++) {
            if (pre_class[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int t = q.size();
            while (t --) {
                int k = q.front();
                q.pop();
                for (auto c: post_class[k]) {
                    pre_class[c] --;
                    if (pre_class[c] == 0)
                        q.push(c);
                }
            }
        }

        for (int i = 0; i < pre_class.size(); i ++)
            if (pre_class[i] != 0)
                return false;
        return true;
    }
};
