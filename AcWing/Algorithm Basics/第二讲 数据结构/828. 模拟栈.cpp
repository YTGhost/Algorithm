#include <iostream>

using namespace std;

const int N = 100010;

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

int query()
{
    return stk[tt]; 
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