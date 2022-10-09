class Solution {
public:
    int integerReplacement(int n) {
        return bfs(n);
    }

    int bfs(unsigned long n) {
        int depth = 0;
        queue<unsigned long> q;
        q.push(n);
        while (!q.empty()) {
            int m = q.size();
            while (m --) {
                unsigned long t = q.front();
                q.pop();
                if (t == 1) return depth;
                if (t % 2 == 0) q.push(t / 2);
                else {
                    q.push(t - 1);
                    q.push(t + 1);
                }
            }
            depth ++;
        }
        return -1;
    }
};
