/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> res;
    vector<int>::iterator it;

    void dfs(vector<NestedInteger> &nestedList) {
        for(auto t : nestedList)
        {
            if(t.isInteger()) {
                res.emplace_back(t.getInteger());
            } else {
                dfs(t.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        it = res.begin();
    }
    
    int next() {
        return *it++;
    }
    
    bool hasNext() {
        return it != res.end();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */