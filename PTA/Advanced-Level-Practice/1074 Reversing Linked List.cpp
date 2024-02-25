#include <iostream>
#include <vector>
using namespace std;

const int N = 100010;
int e[N], ne[N];
vector<int> link;

void reverse(int start, int end) {
    while(start < end) {
        swap(link[start++], link[end--]);
    }
}

int main()
{
    int n, k, head;
    cin >> head >> n >> k;
    for(int i = 0; i < n; i++) {
        int address, data, next;
        cin >> address >> data >> next;
        e[address] = data;
        ne[address] = next;
    }
    for(int i = head; i != -1; i = ne[i]) {
        link.push_back(i);
    }
    for(int i = 0; i + k - 1 < link.size(); i += k) {
        int start = i, end = i + k - 1;
        reverse(start, end);
    }
    for(int i = 0; i < link.size(); i++) {
        printf("%05d %d ", link[i], e[link[i]]);
        if(i == link.size() - 1) cout << -1 << endl;
        else printf("%05d\n", link[i+1]);
    }
    return 0;
}