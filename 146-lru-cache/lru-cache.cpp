class Node {
public:

    int key;
    int value;

    Node* prev;
    Node* next;

    Node(int k, int v) {

        key = k;
        value = v;

        prev = next = NULL;
    }
};

class LRUCache {
public:

    int cap;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {

        cap = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    // remove node
    void remove(Node* node) {

        Node* p = node->prev;
        Node* n = node->next;

        p->next = n;
        n->prev = p;
    }

    // insert after head
    void insert(Node* node) {

        Node* n = head->next;

        head->next = node;
        node->prev = head;

        node->next = n;
        n->prev = node;
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        // already exists
        if (mp.find(key) != mp.end()) {

            Node* oldNode = mp[key];

            remove(oldNode);

            delete oldNode;
        }

        Node* node = new Node(key, value);

        mp[key] = node;

        insert(node);

        // capacity exceeded
        if (mp.size() > cap) {

            Node* lru = tail->prev;

            remove(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};