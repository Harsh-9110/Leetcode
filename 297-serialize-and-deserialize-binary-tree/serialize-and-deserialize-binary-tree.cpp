class Codec {
public:
    // Serialize (DFS preorder)
    void dfsSerialize(TreeNode* root, string& s) {
        if (!root) {
            s += "null,";
            return;
        }
        s += to_string(root->val) + ",";
        dfsSerialize(root->left, s);
        dfsSerialize(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        dfsSerialize(root, s);
        return s;
    }

    // Deserialize
    TreeNode* dfsDeserialize(queue<string>& q) {
        string val = q.front(); q.pop();

        if (val == "null") return NULL;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = dfsDeserialize(q);
        node->right = dfsDeserialize(q);
        return node;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        queue<string> q;

        while (getline(ss, item, ',')) {
            q.push(item);
        }

        return dfsDeserialize(q);
    }
};