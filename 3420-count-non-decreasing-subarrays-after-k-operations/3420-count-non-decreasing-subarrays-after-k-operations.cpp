
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        deque<pair<int, int>> dq;

        long long cost = 0;
        long long ans = 0;

        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            int num = nums[i];
            int count = 1;

            while (!dq.empty() && dq.back().first < num) {

                int val = dq.back().first;
                int cnt = dq.back().second;

                dq.pop_back();

                cost += 1LL * (num - val) * cnt;

                count += cnt;
            }

            dq.push_back({num, count});
            while (cost > k) {

                int rightVal = dq.front().first;
                int rightCount = dq.front().second;

                dq.pop_front();

                cost -= (rightVal - nums[j]);

                j--;

                if (rightCount > 1) {
                    dq.push_front({rightVal, rightCount - 1});
                }
            }
            ans += (j - i + 1);
        }

        return ans;
    }
};
