class RangeModule {
public:

    map<int,int> ranges;

    RangeModule() {

    }

    void addRange(int left,
                  int right) {

        auto it =
            ranges.lower_bound(left);

        // check previous interval
        if (it != ranges.begin()) {

            --it;

            if (it->second < left)
                ++it;
        }

        while (it != ranges.end() &&
               it->first <= right) {

            left =
                min(left, it->first);

            right =
                max(right, it->second);

            it = ranges.erase(it);
        }

        ranges[left] = right;
    }

    bool queryRange(int left,
                    int right) {

        auto it =
            ranges.upper_bound(left);

        if (it == ranges.begin())
            return false;

        --it;

        return it->second >= right;
    }

    void removeRange(int left,
                     int right) {

        auto it =
            ranges.lower_bound(left);

        if (it != ranges.begin()) {

            --it;

            if (it->second <= left)
                ++it;
        }

        vector<pair<int,int>> addBack;

        while (it != ranges.end() &&
               it->first < right) {

            int start = it->first;
            int end = it->second;

            // left remaining part
            if (start < left) {

                addBack.push_back({
                    start,
                    left
                });
            }

            // right remaining part
            if (end > right) {

                addBack.push_back({
                    right,
                    end
                });
            }

            it = ranges.erase(it);
        }

        for (auto& p : addBack) {

            ranges[p.first] =
                p.second;
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */