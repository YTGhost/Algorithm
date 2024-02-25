#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


struct Node {
    int address, data, next;
};

unordered_map<int, Node> m;

int main()
{
    int head1, head2, n;
    cin >> head1 >> head2 >> n;
    for(int i = 0; i < n; i++) {
        int address, data, next;
        cin >> address >> data >> next;
        m[address] = { address, data, next };
    }
    vector<Node> L1, L2;
    // 对于L1遍历
    for(int i = head1; m.count(i); i = m[i].next) {
        L1.push_back(m[i]);
    }
    // 对于L2遍历
    for(int i = head2; m.count(i); i = m[i].next) {
        L2.push_back(m[i]);
    }
    if(L1.size() < L2.size()) swap(L1, L2);
    vector<Node> res;
    int i, j;
    for(i = 0, j = L2.size() - 1; j >= 0; i += 2, j--) {
        res.push_back(L1[i]);
        res.push_back(L1[i + 1]);
        res.push_back(L2[j]);
    }
    for( ; i < L1.size(); i++) {
        res.push_back(L1[i]);
    }
    for(int j = 0; j < res.size(); j++) {
        auto item = res[j];
        if(j == res.size() - 1) printf("%05d %d -1\n", item.address, item.data);
        else printf("%05d %d %05d\n", item.address, item.data, res[j + 1].address);
    }
    return 0;
}