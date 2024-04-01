#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    unordered_map<int, int> hash;
    int l = 0, r = 0, res = 0;
    while(r < n) {
        hash[nums[r]]++;
        while(hash[nums[r]] >= x) {
            res += n - r;
            hash[nums[l]]--;
            l++;
        }
        r++;
    }
    cout << res << endl;
    return 0;
}