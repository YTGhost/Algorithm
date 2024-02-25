#include <iostream>

using namespace std;

const int N = 100010;

int q[N], hh, tt = -1;

void push(int x)
{
    q[++tt] = x;
}

void pop()
{
    hh++;
}

bool empty()
{
    if(hh <= tt) return false;
    else return true;
}

int query()
{
    return q[hh];
}

int main()
{
    int M;
    cin >> M;
    while(M--)
    {
        string op;
        int x;
        cin >> op;
        if(op == "push"){
            cin >> x;
            push(x);
        }else if(op == "pop"){
            pop();
        }else if(op == "empty"){
            if(empty()) cout << "YES" << endl;
            else cout << "NO" << endl;
        }else if(op == "query"){
            cout << query() << endl;
        }
    }
    return 0;
}