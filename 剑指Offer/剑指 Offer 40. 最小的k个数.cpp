// 手写大根堆
class Solution {
public:
    void down(vector<int>& h, int u, int k) {
        int t = u;
        if(u*2 <= k && h[u*2] > h[t]) t = u*2;
        if(u*2+1 <= k && h[u*2+1] > h[t]) t = u*2+1;
        if(t != u)
        {
            swap(h[t], h[u]);
            down(h, t, k);
        }
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k == 0) return vector<int>(0);
        vector<int> h(k+1);
        int n = arr.size();
        for(int i = 1; i <= k; i++) h[i] = arr[i-1];

        for(int i = k/2; i; i--) down(h, i, k);

        for(int i = k; i < n; i++)
        {
            if(arr[i] < h[1]){
                h[1] = arr[i];
                down(h, 1, k);
            }
        }
        return vector<int>(h.begin()+1, h.end());
    }
};

// 优先队列（大根堆）
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k);
        if(k == 0) return res;
        priority_queue<int> heap;
        for(int i = 0; i < k; i++) heap.push(arr[i]);
        for(int i = k; i < arr.size(); i++)
        {
            if(arr[i] < heap.top()){
                heap.pop();
                heap.push(arr[i]);
            }
        }

        for(int i = 0; i < k; i++)
        {
            res[i] = heap.top();
            heap.pop();
        }
        return res;
    }
};