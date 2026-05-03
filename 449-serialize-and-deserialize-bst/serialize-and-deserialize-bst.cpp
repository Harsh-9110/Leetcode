class Codec {
public:
    // Serialize (Preorder)
    void preorder(TreeNode* root, string& s) {
        if (!root) return;

        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    // Deserialize
    TreeNode* build(queue<int>& q, int minVal, int maxVal) {
        if (q.empty()) return NULL;

        int val = q.front();
        if (val < minVal || val > maxVal) return NULL;

        q.pop();

        TreeNode* root = new TreeNode(val);
        root->left = build(q, minVal, val);
        root->right = build(q, val, maxVal);

        return root;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        stringstream ss(data);
        string item;
        queue<int> q;

        while (getline(ss, item, ',')) {
            if (!item.empty())
                q.push(stoi(item));
        }

        return build(q, INT_MIN, INT_MAX);
    }
};