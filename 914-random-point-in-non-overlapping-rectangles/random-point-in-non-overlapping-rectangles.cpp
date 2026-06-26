class Solution {
public:
    vector<vector<int>> rects;
    vector<int> prefix;
    Solution(vector<vector<int>>& rectangles) {
        rects = rectangles;
        int sum = 0;
        for (auto &r : rects) {
            int points =
                (r[2] - r[0] + 1) *
                (r[3] - r[1] + 1);
            sum += points;
            prefix.push_back(sum);
        }
    }

    vector<int> pick() {

        int total = prefix.back();

        int target = rand() % total + 1;

        int idx = lower_bound(
                    prefix.begin(),
                    prefix.end(),
                    target)
                  - prefix.begin();

        auto &r = rects[idx];

        int x =
            r[0] +
            rand() % (r[2] - r[0] + 1);

        int y =
            r[1] +
            rand() % (r[3] - r[1] + 1);

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */