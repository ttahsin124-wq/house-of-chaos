class Solution {
public:
    int minMoves(vector<int>& nums) {
    int sum=0;
    int min_move=1e9;
    int n=nums.size();
    for(int i:nums)
    {
        min_move=min(min_move,i);
        sum+=i;
    }
    return sum-n*min_move;

    }
};