
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long square = 1LL * nums[i] * nums[i];
            if (i < n / 2) {
                sum -= square;
            } else {
                sum += square;
            }
        }
        return sum;
    }
};