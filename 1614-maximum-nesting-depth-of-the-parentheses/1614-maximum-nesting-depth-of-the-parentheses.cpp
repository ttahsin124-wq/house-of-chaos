class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int maxopen = 0;
        for (char c : s) {
            if (c == '(') {
                open++;
                maxopen = max(open, maxopen);
            }
            if (c == ')') {
                open--;
            }
        }
        return maxopen;
    }
};