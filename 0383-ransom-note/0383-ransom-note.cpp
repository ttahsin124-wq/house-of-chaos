
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int freq[26] = {0};

        for (int i = 0; i < magazine.size(); i++) {
            freq[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.size(); i++) {

            if (freq[ransomNote[i] - 'a'] == 0) {
                return false;
            }

            freq[ransomNote[i] - 'a']--;
        }

        return true;
    }
};

