#include <iostream>
#include <set>
#include <stack>
using namespace std;

const int N = 100010;
int n;

multiset<int> up, down;
stack<int> stk;

void adjust()
{
    while(up.size() > down.size()) {
        auto it = up.begin();
        down.insert(*it);
        up.erase(it);
    }
    
    while(down.size() > up.size() + 1) {
        auto it = down.end();
        it--;
        up.insert(*it);
        down.erase(it);
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if(op == "Push") {
            int x;
            cin >> x;
            stk.push(x);
            if(up.empty() || x < *up.begin()) down.insert(x);
            else up.insert(x);
            adjust();
        } else if(op == "Pop") {
            if(stk.empty()) puts("Invalid");
            else {
                int t = stk.top();
                stk.pop();
                printf("%d\n", t);
                auto it = down.end();
                it--;
                if(t <= *it) down.erase(down.find(t));
                else up.erase(up.find(t));
                adjust();
            }
        } else {
            if(stk.empty()) puts("Invalid");
            else {
                auto it = down.end();
                it--;
                printf("%d\n", *it);
            }
        }
    }
    return 0;
}