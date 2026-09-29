class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if ((m + n - 1) % 2 != 0) // Total path length must be even
        {
            return false;
        }
        if (grid[0][0] == ')') // first character must be '('
        {
            return false;
        }
        queue<vector<int>> q;
        q.push({0, 0, 1});
        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(n, vector<bool>(m + n, false)));
        visited[0][0][1] = true;
        int directions[2][2] = {{1, 0}, {0, 1}};
        while (!q.empty()) {
            vector<int> current = q.front();
            q.pop();
            int row = current[0];
            int col = current[1];
            int balance = current[2];
            if (row == m - 1 && col == n - 1) {
                if (balance == 0) {
                    return true;
                }
            }
            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                int newBalance = balance;
                if (newRow >= m || newCol >= n) {
                    continue;
                }
                if (grid[newRow][newCol] == '(') {
                    newBalance++;
                } else {
                    newBalance--;
                }
                if (newBalance < 0)
                    continue;
                if (visited[newRow][newCol][newBalance])
                    continue;
                visited[newRow][newCol][newBalance] = true;
                q.push({newRow, newCol, newBalance});
            }
        }
        return false;
    }
};