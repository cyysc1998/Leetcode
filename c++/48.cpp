class Solution {
public:

    void rotate_pixel(vector<vector<int>>& matrix, int x, int y) {
        int h = matrix.size() - 1;
        int x1 = x, y1 = y;
        int x2 = y, y2 = h - x;
        int x3 = h - x, y3 = h - y;
        int x4 = h - y, y4 = x;
        int t = matrix[x1][y1];
        matrix[x1][y1] = matrix[x4][y4];
        matrix[x4][y4] = matrix[x3][y3];
        matrix[x3][y3] = matrix[x2][y2];
        matrix[x2][y2] = t;
    }

    void rotate(vector<vector<int>>& matrix) {
        int h = matrix.size();
        int rh = (h - 1) / 2;
        
        if (h % 2 == 1) {
            for (int i = 0; i < rh; i ++)
                for (int j = 0; j < rh; j ++)
                    rotate_pixel(matrix, i, j);
            for (int i = 0; i < rh; i ++)
                rotate_pixel(matrix, i, rh);
        }
        else {
            for (int i = 0; i <= rh; i ++)
                for (int j = 0; j <= rh; j ++)
                    rotate_pixel(matrix, i, j);
        }
    }
};
