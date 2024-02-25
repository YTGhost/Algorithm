#include <iostream>
#include <vector>
using namespace std;

const int N = 100010;
int e[N], ne[N];

int main()
{
    int head, n, k;
    cin >> head >> n >> k;
    for(int i = 0; i < n; i++) {
        int address, data, next;
        cin >> address >> data >> next;
        e[address] = data;
        ne[address] = next;
    }
    vector<int> link;
    vector<int> neg;
    vector<int> nor;
    vector<int> front;
    vector<int> back;
    vector<int> res;
    for(int i = head; i != -1; i = ne[i]) {
        link.push_back(i);
    }
    for(int i = 0; i < link.size(); i++) {
        if(e[link[i]] < 0) neg.push_back(link[i]);
        else nor.push_back(link[i]);
    }
    for(int i = 0; i < nor.size(); i++) {
        if(e[nor[i]] > k) back.push_back(nor[i]);
        else front.push_back(nor[i]);
    }
    for(int i = 0; i < neg.size(); i++) res.push_back(neg[i]);
    for(int i = 0; i < front.size(); i++) res.push_back(front[i]);
    for(int i = 0; i < back.size(); i++) res.push_back(back[i]);
    for(int i = 0; i < res.size(); i++) {
        if(i == res.size()-1) ne[res[i]] = -1;
        else ne[res[i]] = res[i+1];
    }
    for(int i = 0; i < res.size(); i++) {
        if(ne[res[i]] != -1) {
            printf("%05d %d %05d\n", res[i], e[res[i]], ne[res[i]]);
        } else {
            printf("%05d %d %d\n", res[i], e[res[i]], ne[res[i]]); 
        }
    }
    return 0;
}