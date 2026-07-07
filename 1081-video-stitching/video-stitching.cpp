class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> reach(time + 1, 0);
        for (auto &clip : clips) {
            if (clip[0] <= time)
                reach[clip[0]] = max(reach[clip[0]], clip[1]);
        }
        int clipsUsed = 0;
        int currEnd = 0;
        int far = 0;
        for (int i = 0; i < time; i++) {
            far = max(far, reach[i]);

            if (i == currEnd) {
                if (far <= i)
                    return -1;
                clipsUsed++;
                currEnd = far;
            }
        }
        return clipsUsed;
    }
};