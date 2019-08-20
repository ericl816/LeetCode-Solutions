class Solution {
public:

    // TODO: Optimization of removing string since string building is costly (strings are immutable in Java)

    int indeg[26];
    map<char, set<char> > adj;

    void buildGraph (vector<string> &words) {
        for (size_t i=1; i<words.size(); i++) {
            string curr = words[i - 1], next = words[i];
            for (size_t j=0; j<min(curr.size(), next.size()); j++) {
                char par = curr[j], child = next[j];
                if (par != child) {
                    if (!adj[par].count(child)) {
                        adj[par].insert(child);
                        indeg[child - 'a']++;
                    }
                    break;
                }
            }
        }
    }

    string topologicalSort () {
        string ans = "";
        queue<char> q;
        // Get keyset of chars in adjacency map
        for (auto it=adj.begin(); it!=adj.end(); it++) {
            char ch = it->first;
            if (!indeg[ch - 'a']) q.push(ch);
        }
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            ans += curr;
            for (auto i : adj[curr]) {
                if (!(--indeg[i - 'a'])) q.push(i);
            }
        }
        // We have a cycle only if result's string length is less than number of nodes
        return ans.size() != adj.size() ? "" : ans;
    }

    string alienOrder (vector<string>& words) {
        buildGraph(words);
        return topologicalSort();
    }
};