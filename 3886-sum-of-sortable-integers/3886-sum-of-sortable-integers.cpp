class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool ok = true;
            int prevMax = -1;

            for (int i = 0; i < n; i += k) {
                int mn = nums[i];
                int mx = nums[i];
                int descents = 0;

                for (int j = i; j < i + k; j++) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);

                    if (j > i && nums[j - 1] > nums[j]) {
                        descents++;
                    }
                }

                // Check the circular order of this block.
                if (k > 1 && nums[i + k - 1] > nums[i]) {
                    descents++;
                }

                if (descents > 1) {
                    ok = false;
                    break;
                }

                if (i > 0 && prevMax > mn) {
                    ok = false;
                    break;
                }

                prevMax = mx;
            }

            if (ok) {
                ans += k;
            }
        }

        return ans;
    }
};