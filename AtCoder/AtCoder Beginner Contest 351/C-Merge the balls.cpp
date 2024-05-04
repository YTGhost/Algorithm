#include <iostream>
using namespace std;

const int N = 200010;

int stk[N], tt;

void push(int x)
{
    stk[++tt] = x;
}

void pop()
{
    tt--;
}

bool empty()
{
    if(tt > 0) return false;
    else return true;
}

int top()
{
    return stk[tt]; 
}

int size()
{
    return tt;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(empty() || top() != x) {
            push(x);
        } else {
            push(x);
            while(size() > 1 && top() == stk[tt - 1]) {
                int t = top();
                pop();
                pop();
                push(t + 1);
            }
        }
    }
    cout << size() << endl;
    return 0;
}