#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int head, n, k;

struct Node {
    int address, data, next;
};

int main()
{
    vector<Node> list;
    vector<vector<Node>> blockList;
    unordered_map<int, Node> m;
    cin >> head >> n >> k;
    for(int i = 0; i < n; i++) {
        int address, data, next;
        cin >> address >> data >> next;
        m[address] = { address, data, next };
    }
    for(int i = head; i != -1; i = m[i].next) {
        list.push_back(m[i]);
    }
    vector<Node> block;
    for(int i = 0; i < list.size(); i++) {
        block.push_back(list[i]);
        if(i % k == k-1) {
            blockList.push_back(block);
            block.clear();
        }
    }
    if(block.size()) blockList.push_back(block);
    int l = 0, r = blockList.size() - 1;
    while(l < r) {
        swap(blockList[l++], blockList[r--]);
    }
    vector<Node> resList;
    for(int i = 0; i < blockList.size(); i++) {
        for(int j = 0; j < blockList[i].size(); j++) {
            resList.push_back(blockList[i][j]);
        }
    }
    for(int i = 0; i < resList.size(); i++) {
        if(i == resList.size() - 1) printf("%05d %d -1\n", resList[i].address, resList[i].data);
        else printf("%05d %d %05d\n", resList[i].address, resList[i].data, resList[i + 1].address);
    }
    return 0;
}