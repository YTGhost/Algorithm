#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int l = 0, r = 0, res = INT_MAX;
    while(r < n) {
        while(nums[r] - nums[l] + 1 > n) l++;
        res = min(res, n - (r - l + 1));
        r++;
    }
    cout << res << endl;
    return 0;
}