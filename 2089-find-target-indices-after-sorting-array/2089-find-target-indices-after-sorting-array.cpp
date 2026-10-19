class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) { //as target shpuld meet the indexes
            if (nums[i] == target)

            {
                ans.push_back(i);
            }
        }
          return ans;
    }
  
};