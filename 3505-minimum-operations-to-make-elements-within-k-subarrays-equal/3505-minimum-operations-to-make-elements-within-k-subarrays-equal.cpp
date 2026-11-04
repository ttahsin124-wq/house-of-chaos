
class Solution {
public:
    multiset<int> left, right;
    long long sumLeft = 0, sumRight = 0;

    void balance() {
        int need = (left.size() + right.size() + 1) / 2;

        while (left.size() > need) {
            int val = *left.rbegin();

            left.erase(left.find(val));
            sumLeft -= val;

            right.insert(val);
            sumRight += val;
        }

        while (left.size() < need) {
            int val = *right.begin();

            right.erase(right.find(val));
            sumRight -= val;

            left.insert(val);
            sumLeft += val;
        }
    }

    void add(int val) {
        if (left.empty() || val <= *left.rbegin()) {
            left.insert(val);
            sumLeft += val;
        }
        else {
            right.insert(val);
            sumRight += val;
        }

        balance();
    }

    void remove(int val) {
        auto it = left.find(val);

        if (it != left.end()) {
            left.erase(it);
            sumLeft -= val;
        }
        else {
            it = right.find(val);
            right.erase(it);
            sumRight -= val;
        }

        balance();
    }

    long long getCost() {
        long long median = *left.rbegin();

        long long costLeft =
            median * left.size() - sumLeft;

        long long costRight =
            sumRight - median * right.size();

        return costLeft + costRight;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);

        left.clear();
        right.clear();
        sumLeft = 0;
        sumRight = 0;

   
        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                dp[i][j] = dp[i - 1][j];

                if (i >= x && dp[i - x][j - 1] != INF) {

                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
