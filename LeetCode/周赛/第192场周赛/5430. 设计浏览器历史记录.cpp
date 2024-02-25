class BrowserHistory {
public:
    string cur;
    vector<string> history;
    int index;
    BrowserHistory(string homepage) {
        cur = homepage;
        history.push_back(homepage);
        index = 0;
    }
    
    void visit(string url) {
        if(index != history.size()-1)
        {
            auto begin = history.begin() + index + 1;
            history.erase(begin, history.end());
        }
        cur = url;
        index++;
        history.push_back(url);
    }
    
    string back(int steps) {
        if(steps > index) index = 0;
        else index -= steps;
        cur = history[index];
        return cur;
    }
    
    string forward(int steps) {
        if(index + steps >= history.size()) index = history.size()-1;
        else index += steps;
        cur = history[index];
        return cur;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */