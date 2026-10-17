
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int x : nums) {
            int sum = 0;
            int temp = x;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            arr.push_back({sum, x});
        }
        sort(arr.begin(), arr.end());
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[nums[i]] = i;
        }
        int swaps = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] || index[arr[i].second] == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;

                j = index[arr[j].second];
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};
