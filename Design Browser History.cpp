class BrowserHistory {
public:
    vector<string> vec;
    int idx = 0;
    
    BrowserHistory(string homepage) {
        vec.push_back(homepage);
    }
    
    void visit(string url) {
        if (idx + 1 < vec.size()) {
            vec.resize(idx + 1);
            vec.shrink_to_fit();
        }
        vec.push_back(url);
        ++idx;
    }
    
    string back(int steps) {
        idx = max(idx - steps, 0);
        return vec[idx];
    }
    
    string forward(int steps) {
        idx = min(idx + steps, (int) vec.size() - 1);
        return vec[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
