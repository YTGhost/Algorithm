class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        struct Node {
            double v;
            int a, b;
            bool operator < (const Node& t) const {
                return v < t.v;
            } 
        };
        // 多路归并模型
        // 大根堆
        priority_queue<Node> heap;
        double sum = 0;
        for(auto& c : classes)
        {
            int a = c[1], b = c[0];
            sum += (double) b / a;
            heap.push({(a - b) / (a * (a + 1.0)), a, b});
        }
        while(extraStudents--)
        {
            auto t = heap.top();
            heap.pop();
            sum += t.v;
            int a = t.a + 1, b = t.b + 1;
            heap.push({(a - b) / (a * (a + 1.0)), a, b});
        }
        return sum / classes.size();
    }
};