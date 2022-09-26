class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return search(matrix, target, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
    }

    bool search(vector<vector<int>>& matrix, int target, int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2) return false;
        if (matrix[x1][y1] > target || matrix[x2][y2] < target) return false;
        if (x1 == x2 && y1 == y2) return matrix[x1][y1] == target;

        int mid_x = x1 + (x2 - x1) / 2;
        int mid_y = y1 + (y2 - y1) / 2;

        if (search(matrix, target, x1, y1, mid_x, mid_y)) return true;
        else if (search(matrix, target, mid_x + 1, y1, x2, mid_y)) return true;
        else if (search(matrix, target, x1, mid_y + 1, mid_x, y2)) return true;
        else if (search(matrix, target, mid_x + 1, mid_y + 1, x2, y2)) return true;
        else return false;
    }

};
