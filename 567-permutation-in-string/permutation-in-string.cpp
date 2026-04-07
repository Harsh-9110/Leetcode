class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26, 0), count2(26, 0);

        for (char c : s1)
            count1[c - 'a']++;

        int window = s1.size();

        for (int i = 0; i < s2.size(); i++) {
            count2[s2[i] - 'a']++;

            // maintain window size
            if (i >= window) {
                count2[s2[i - window] - 'a']--;
            }

            // compare
            if (count1 == count2)
                return true;
        }

        return false;
    }
};