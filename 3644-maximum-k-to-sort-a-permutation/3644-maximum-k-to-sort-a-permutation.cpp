class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = 0;
        bool found = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                if (!found) {
                    ans = i;
                    found = true;
                } else {
                    ans &= i;
                }
            }
        }
        return ans;
    }
};