class OrderedStream {
    public:
        int ptr, n;
        vector<string> a;
        OrderedStream(int _n) {
            n = _n;
            a.resize(n);
            ptr = 1;
        }
        
        vector<string> insert(int idKey, string value) {
            a[idKey - 1] = value;
            vector<string> res;
            if (ptr < idKey) return res;
            while (ptr <= n && a[ptr - 1] != "") {
                res.push_back(a[ptr - 1]);
                ptr++;
            }
            return res;
        }
    };
    
    /**
     * Your OrderedStream object will be instantiated and called as such:
     * OrderedStream* obj = new OrderedStream(n);
     * vector<string> param_1 = obj->insert(idKey,value);
     */