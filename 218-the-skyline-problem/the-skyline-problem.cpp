class Solution {
public:
    vector<vector<int>> getSkyline(
        vector<vector<int>>& buildings) {
        vector<pair<int,int>> events;
        for (auto &b : buildings) {
            int L = b[0];
            int R = b[1];
            int H = b[2];
            events.push_back({L, -H});
            events.push_back({R, H});
        }
        sort(events.begin(), events.end());
        multiset<int> heights;
        heights.insert(0);
        int prevMax = 0;
        vector<vector<int>> ans;
        for (auto &[x, h] : events) {
            if (h < 0) {

                heights.insert(-h);
            }
            else {

                heights.erase(
                    heights.find(h)
                );
            }

            int currMax =
                *heights.rbegin();

            if (currMax != prevMax) {

                ans.push_back(
                    {x, currMax}
                );

                prevMax = currMax;
            }
        }

        return ans;
    }
};