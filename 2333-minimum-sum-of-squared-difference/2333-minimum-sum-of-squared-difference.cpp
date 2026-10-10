
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        int maxDiff = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }

        long long total = 0;
        for (int x : diff) {
            total += x;
        }

        if (total <= k) {
            return 0;
        }

        int low = 0, high = maxDiff;

        while (low < high) {
            int mid = low + (high - low) / 2;

            long long need = 0;

            for (int x : diff) {
                if (x > mid) {
                    need += x - mid;
                }
            }

            if (need <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int level = low;
        long long remaining = k;
        long long answer = 0;

        for (int x : diff) {
            if (x > level) {
                remaining -= x - level;
                answer += 1LL * level * level;
            } else {
                answer += 1LL * x * x;
            }
        }
        for (int x : diff) {
            if (remaining > 0 && x >= level && level > 0) {
                answer -= 2LL * level - 1;
                remaining--;
            }
        }

        return answer;
    }
};