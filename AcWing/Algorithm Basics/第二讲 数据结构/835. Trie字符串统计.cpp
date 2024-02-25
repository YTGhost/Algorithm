#include <iostream>

using namespace std;

const int N = 100010;

char str[N];

// 下标为0的节点，既是根结点，也是空节点（节点没有子节点的话也会让它指向0）
int son[N][26]; // 字符串只包含小写字母，所以每个节点最多有二十六个分支
int cnt[N]; // 以当前这个点为结尾的单词有多少个
int idx;    // 当前用到了哪一个下标

void insert(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        char op;
        cin >> op >> str;
        if(op == 'I') insert(str);
        else cout << query(str) << endl;
    }
    return 0;
}