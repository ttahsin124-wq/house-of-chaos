class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int ans = 0;
        for (char ch : s) {
            if (ch == '(') {
                count++;
            } else {
                if (count > 0) {
                    count--;
                }
                else
                {
                    ans++;
                }
            }
        }
        return abs(count)+ans;
    }
};