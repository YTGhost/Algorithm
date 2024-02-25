#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int h[N], s, i;
int ph[N];  // 第k个插入的值下标为多少
int hp[N];  // 下标为k的值是第几个插入的

void heap_swap(int a, int b)
{
    swap(h[a], h[b]);
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
}

void up(int x)
{
    while(x/2 && h[x/2] > h[x])
    {
        heap_swap(x, x/2);
        x /= 2;
    }
}

void down(int x)
{
    int t = x;
    if(x*2 <= s && h[x*2] < h[t]) t = x*2;
    if(x*2+1 <= s && h[x*2+1] < h[t]) t = x*2+1;
    if(t != x)
    {
        heap_swap(t, x);
        down(t);
    }
}

void insert(int x)
{
    h[++s] = x;
    i++;
    ph[i] = s;
    hp[s] = i;
    up(s);
}

void getTop()
{
    cout << h[1] << endl;
}

void deleteTop()
{
    heap_swap(1, s);
    s--;
    down(1);
}

void deleteK(int k)
{
    k = ph[k];
    heap_swap(k, s);
    s--;
    down(k);
    up(k);
}

void modifyK(int k, int x)
{
    k = ph[k];
    h[k] = x;
    down(k);
    up(k);
}

int main()
{
    int n;
    cin >> n;

    while(n--)
    {
        string op;
        cin >> op;
        if(op == "I"){
            int x;
            cin >> x;
            insert(x);
        }else if(op == "PM"){
            getTop();
        }else if(op == "DM"){
            deleteTop();
        }else if(op == "D"){
            int k;
            cin >> k;
            deleteK(k);
        }else{
            int k, x;
            cin >> k >> x;
            modifyK(k, x);
        }
    }
    return 0;
}