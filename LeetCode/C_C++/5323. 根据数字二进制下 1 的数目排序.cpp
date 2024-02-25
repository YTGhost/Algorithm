class Solution {
public:
    static bool cmp(pair<int, int>& x, pair<int, int>& y)
    {
        if(x.second == y.second)
        {
            return x.first < y.first;
        }
        return x.second < y.second;
    }
    vector<pair<int, int>> m;
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>::iterator it;
        for(it = arr.begin(); it != arr.end(); it++)
        {
            int num = *it;
            int count = 0;
            while(num)
            {
                if(num%2 != 0)
                {
                    count++;
                }
                num /=2;
            }
            m.push_back(pair<int, int>(*it, count));
        }
        sort(m.begin(), m.end(), cmp);
        vector<int> a;
        for(auto it : m)
        {
            a.push_back(it.first);
        }
        return a;
    }
};