#include <iostream>

using namespace std;

const int N = 100010;

// head 表示头节点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针是多少
// idx 存储当前已经用到了哪个点
int head, e[N], ne[N], idx;

// 初始化
void init()
{
    head = -1;
    idx = 0;
}

// 将x插到头节点
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

// 将x插到下标是k的节点后面
void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

// 将下标是k的节点后面的节点删掉
void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int M;
    cin >> M;
    init();
    while(M--)
    {
        char op;
        int k, x;
        cin >> op;
        
        if(op == 'H'){
            cin >> x;
            add_to_head(x);
        }else if(op == 'D'){
            cin >> k;
            if(!k) head = ne[head]; // 特判删除头结点
            else remove(k-1);
        }else{
            cin >> k >> x;
            add(k-1, x);
        }
    }
    for(int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    cout << endl;
    return 0;
}