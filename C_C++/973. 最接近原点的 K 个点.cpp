class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>> q;
        vector<vector<int>> res;
        for(int i = 0; i < K; i++)
        {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            q.push({dist, i});
        }
        for(int i = K; i < points.size(); i++)
        {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if(dist < q.top().first)
            {
                q.pop();
                q.push({dist, i});
            }
        }
        while(!q.empty())
        {
            res.emplace_back(points[q.top().second]);
            q.pop();
        }
        return res;
    }
};