
class Solution {
public:
    int minimumChanges(string s, int k) {

        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int len = 2; len <= n; len++) {

            for (int l = 0; l + len <= n; l++) {

                int changes = INF;
                int r = l + len - 1;

                // Try every valid divisor
                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int groups = d;
                    int groupSize = len / d;

                    int cnt = 0;


                    for (int g = 0; g < groups; g++) {

                        for (int x = 0; x < groupSize / 2; x++) {

                            int a = l + g + x * d;

                            int b = l + g +
                                    (groupSize - 1 - x) * d;

                            if (s[a] != s[b]) {
                                cnt++;
                            }
                        }
                    }

                    changes = min(changes, cnt);
                }

                cost[l][r] = changes;
            }
        }


        vector<vector<int>> dp(
            k + 1, vector<int>(n + 1, INF)
        );

        dp[0][0] = 0;

        
        for (int i = 1; i <= k; i++) {

            for (int j = 2 * i; j <= n; j++) {

                for (int p = 2 * (i - 1); p <= j - 2; p++) {

                    if (dp[i - 1][p] == INF)
                        continue;

                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - 1][p] + cost[p][j - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
