#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 100010;

struct Node
{
    int address;
    int key;
    int next;
};

bool cmp(Node a, Node b)
{
    return a.key < b.key;
}

int main()
{
    int n;
    int head;
    cin >> n >> head;
    vector<Node> nodes;
    unordered_map<int, Node> map;
    
    for(int i = 0; i < n; i++) {
        int address, next, key;
        cin >> address >> key >> next;
        map[address] = {address, key, next};
    }
    for(int i = head; i != -1; i = map[i].next) {
        nodes.push_back(map[i]);
    }
    if(nodes.size()) {
        sort(nodes.begin(), nodes.end(), cmp);
        head = nodes[0].address;
        printf("%d %05d\n", nodes.size(), head);
        for(int i = 0; i < nodes.size(); i++) {
            if(i == nodes.size()-1) {
                nodes[i].next = -1;
            } else {
                nodes[i].next = nodes[i+1].address;
            }
            if(nodes[i].next == -1) {
                printf("%05d %d %d\n", nodes[i].address, nodes[i].key, nodes[i].next);
            } else {
                printf("%05d %d %05d\n", nodes[i].address, nodes[i].key, nodes[i].next);
            }
            
        }
    } else {
        cout << "0 -1" << endl;
    }
    return 0;
}