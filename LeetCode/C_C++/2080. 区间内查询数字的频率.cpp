class RangeFreqQuery {
    public:
        unordered_map<int, vector<int>> mp;
        RangeFreqQuery(vector<int>& arr) {
            int n = arr.size();
            for (int i = 0; i < n; i++) {
                mp[arr[i]].push_back(i);
            }
        }
        
        int query(int left, int right, int value) {
            auto it = mp.find(value);
            if (it == mp.end()) {
                return 0;
            }
            return ranges::upper_bound(it->second, right) - ranges::lower_bound(it->second, left);
        }
    };
    
    /**
     * Your RangeFreqQuery object will be instantiated and called as such:
     * RangeFreqQuery* obj = new RangeFreqQuery(arr);
     * int param_1 = obj->query(left,right,value);
     */