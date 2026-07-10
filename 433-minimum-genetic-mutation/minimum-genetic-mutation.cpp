class Solution {
public: 
    int minMutation(string startGene,
                    string endGene,
                    vector<string>& bank) {
        unordered_set<string> genes(
            bank.begin(),
            bank.end()
        );
        // endGene must exist
        if (!genes.count(endGene))
            return -1;
        queue<pair<string,int>> q;
        q.push({startGene, 0});
        vector<char> choices = {
            'A', 'C', 'G', 'T'
        };
        while (!q.empty()) {
            auto [gene, steps] =
                q.front();
            q.pop();
            // reached target
            if (gene == endGene)
                return steps;
            for (int i = 0;
                 i < 8;
                 i++) {
                char oldChar = gene[i];
                for (char ch : choices) {
                    gene[i] = ch;
                    if (genes.count(gene)) {
                        q.push({
                            gene,
                            steps + 1
                        });
                        // mark visited
                        genes.erase(gene);
                    }
                }
                gene[i] = oldChar;
            }
        }
        return -1;
    }
};