class Node {
public:

    int key;
    int value;
    int freq;

    Node(int k, int v) {

        key = k;
        value = v;
        freq = 1;
    }
};

class LFUCache {
public:

    int cap;
    int minFreq;

    unordered_map<int,
        list<Node>::iterator> keyTable;

    unordered_map<int,
        list<Node>> freqTable;

    LFUCache(int capacity) {

        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {

        if (keyTable.find(key)
            == keyTable.end()) {

            return -1;
        }

        auto nodeIt = keyTable[key];

        int keyVal = nodeIt->key;
        int val = nodeIt->value;
        int freq = nodeIt->freq;

        // remove from old frequency list
        freqTable[freq].erase(nodeIt);

        // update minFreq
        if (freqTable[freq].empty()) {

            freqTable.erase(freq);

            if (minFreq == freq)
                minFreq++;
        }

        // add to new frequency list
        freqTable[freq + 1]
            .push_front(Node(keyVal, val));

        freqTable[freq + 1]
            .front().freq = freq + 1;

        keyTable[keyVal] =
            freqTable[freq + 1].begin();

        return val;
    }

    void put(int key, int value) {

        if (cap == 0)
            return;

        // already exists
        if (keyTable.find(key)
            != keyTable.end()) {

            keyTable[key]->value = value;

            get(key);

            return;
        }

        // full cache
        if (keyTable.size() == cap) {

            auto node =
                freqTable[minFreq].back();

            int keyToRemove = node.key;

            freqTable[minFreq].pop_back();

            if (freqTable[minFreq].empty())
                freqTable.erase(minFreq);

            keyTable.erase(keyToRemove);
        }

        // insert new node
        freqTable[1]
            .push_front(Node(key, value));

        keyTable[key] =
            freqTable[1].begin();

        minFreq = 1;
    }
};