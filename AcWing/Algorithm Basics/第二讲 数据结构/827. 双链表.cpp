#include <iostream>

using namespace std;

const int N = 100010;

// e[i] 表示节点i的值
// l[i] 表示节点i的左边是谁
// r[i] 表示节点i的右边是谁
// idx 存储当前已经用到了哪个点
int e[N], l[N], r[N], idx;

// 初始化
void init()
{
    // 0表示左端点, 1表示右端点,都是哨兵节点
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

// 在下标是k的点的右边，插入x
void add(int k, int x)
{
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

// 删除第k个点
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    int M;
    cin >> M;
    init();
    
    while(M--)
    {
        string op;
        int k, x;
        cin >> op;
        if(op == "L"){  // 添加到左哨兵的右边
            cin >> x;
            add(0, x);
        }else if(op == "R"){    // 添加到右哨兵的左边，相当于添加到右哨兵左边节点的右边
            cin >> x;
            add(l[1], x);
        }else if(op == "D"){    // 删除第k个插入节点，k-1+2 = k+1
            cin >> k;
            remove(k+1);
        }else if(op == "IL"){   // 即在第k个插入节点左边节点的右侧插入
            cin >> k >> x;
            add(l[k+1], x);
        }else if(op == "IR"){   // 在第k个插入节点右侧插入
            cin >> k >> x;
            add(k+1, x);
        }
    }
    for(int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
    cout << endl;
    return 0;
}