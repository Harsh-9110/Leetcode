class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if (n % groupSize != 0)
            return false;

        map<int, int> freq;

        for (int card : hand)
            freq[card]++;

        for (auto& it : freq) {

            int card = it.first;
            int count = it.second;

            if (count > 0) {

                for (int i = 0; i < groupSize; i++) {

                    int curr = card + i;

                    if (freq[curr] < count)
                        return false;

                    freq[curr] -= count;
                }
            }
        }

        return true;
    }
};