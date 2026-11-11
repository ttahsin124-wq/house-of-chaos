
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long costA = 1LL * need1 * cost1+ 1LL * need2 * cost2;
        int common = min(need1, need2);
        long long costB = 1LL * common * costBoth+ 1LL * (need1 - common) * cost1+ 1LL * (need2 - common) * cost2;
        int maximum = max(need1, need2);
        long long costC = 1LL * maximum * costBoth;
        return min({costA, costB, costC});
    }
};
