class RandomizedCollection {
public:

    vector<int> nums;

    unordered_map<int,
        unordered_set<int>> mp;

    RandomizedCollection() {

    }

    bool insert(int val) {

        bool notPresent =
            (mp[val].empty());

        nums.push_back(val);

        mp[val].insert(nums.size() - 1);

        return notPresent;
    }

    bool remove(int val) {

        if (mp[val].empty())
            return false;

        // get one index of val
        int idx = *mp[val].begin();

        mp[val].erase(idx);

        int last = nums.back();

        // move last element
        nums[idx] = last;

        // update last element indices
        mp[last].insert(idx);

        mp[last].erase(nums.size() - 1);

        nums.pop_back();

        return true;
    }

    int getRandom() {

        return nums[rand() % nums.size()];
    }
};