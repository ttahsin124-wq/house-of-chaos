class Solution {
public:
    bool isValid(string s) {

        int full = 0;

        while (s.size() > 0) {

            bool found = false;

            for (int i = 0; i < s.size() - 1; i++) {
 
                if ((s[i] == '(' && s[i + 1] == ')') ||
                    (s[i] == '{' && s[i + 1] == '}') ||
                    (s[i] == '[' && s[i + 1] == ']')) {

                    s.erase(i, 2);
                    found = true;
                    break;
                }
            }

            if (!found) {
                return false;
            }
        }

        return true;
    }
};