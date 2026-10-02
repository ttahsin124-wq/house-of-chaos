class Solution {
public:
    void backtrack(int n, int o, int c, string current,
                   vector<string>& ans) {

        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }
        if (o < n) {
            backtrack(n, o + 1, c, current + "(", ans);
        }
        if (c < o) {
            backtrack(n, o, c + 1, current + ")", ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(n, 0, 0, "", ans);
        return ans;
    }
};