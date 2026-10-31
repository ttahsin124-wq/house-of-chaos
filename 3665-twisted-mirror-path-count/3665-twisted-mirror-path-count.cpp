
class Solution {
public:
    const int MOD = 1e9 + 7;

    int m, n;
    vector<vector<int>> grid;

    vector<vector<vector<pair<int,int>>>> memo;
    vector<vector<vector<bool>>> vis;


    pair<int,int> solve(int r, int c, int dir) {

        
        if (r >= m || c >= n)
            return {-1, -1};

     
        if (r == m-1 && c == n-1)
            return {r, c};

 
        if (vis[r][c][dir])
            return memo[r][c][dir];

        vis[r][c][dir] = true;

        if (grid[r][c] == 0) {
            return memo[r][c][dir] = {r, c};
        }

        if (dir == 0) {
         
            return memo[r][c][dir] = solve(r+1, c, 1);
        }
        else {
            return memo[r][c][dir] = solve(r, c+1, 0);
        }
    }

    int uniquePaths(vector<vector<int>>& g) {

        grid = g;
        m = grid.size();
        n = grid[0].size();

        memo.assign(m, vector<vector<pair<int,int>>>(
            n, vector<pair<int,int>>(2, {-1,-1})
        ));

        vis.assign(m, vector<vector<bool>>(
            n, vector<bool>(2, false)
        ));

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (dp[i][j] == 0)
                    continue;

                auto p1 = solve(i, j+1, 0);

                if (p1.first != -1) {
                    dp[p1.first][p1.second] =
                    (dp[p1.first][p1.second] + dp[i][j]) % MOD;
                }

                auto p2 = solve(i+1, j, 1);

                if (p2.first != -1) {
                    dp[p2.first][p2.second] =
                    (dp[p2.first][p2.second] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m-1][n-1];
    }
};
