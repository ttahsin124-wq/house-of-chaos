
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        // Step 1: Calculate free items for every item
        vector<int> freeCount(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeCount[i]++;
                }
            }
        }

        // Step 2: DP
        const int NEG = -1000000000;

        // dp[b] = maximum items using exactly b money
        vector<int> dp(budget + 1, NEG);

        dp[0] = 0;

        // Step 3: Process each item type
        for (int i = 0; i < n; i++) {

            int price = items[i][1];
            int bonus = freeCount[i];

            vector<int> next = dp;

            // active[b] = maximum items when
            // current item has been bought at least once
            vector<int> active(budget + 1, NEG);

            for (int b = price; b <= budget; b++) {

                // Buy the first copy of this item
                active[b] = dp[b - price] + 1 + bonus;

                // Buy another copy of this item
                active[b] = max(
                    active[b],
                    active[b - price] + 1
                );

                next[b] = max(next[b], active[b]);
            }

            dp = next;
        }

        int ans = 0;

        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b]);
        }

        return ans;
    }
};
