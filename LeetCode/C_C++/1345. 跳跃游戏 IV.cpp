class Solution {
public:
    int minJumps(vector<int>& arr) {
      const int inf = 0x3f3f3f3f;
      int n = arr.size();
      unordered_map<int, vector<int>> map;
      for(int i = n - 1; ~i; i--) {
        map[arr[i]].push_back(i);
      }
      vector<int> dist(n, inf);
      queue<int> q;
      q.push(0);
      dist[0] = 0;
      while(q.size()) {
        auto item = q.front();
        int step = dist[item];
        q.pop();
        if(item == n - 1) return step;
        if(item + 1 < n && dist[item + 1] == inf) {
          q.push(item + 1);
          dist[item + 1] = step + 1;
        }
        if(item - 1 >= 0 && dist[item - 1] == inf) {
          q.push(item - 1);
          dist[item - 1] = step + 1;
        }
        for(auto i : map[arr[item]]) {
          if(dist[i] == inf) {
            q.push(i);
            dist[i] = step + 1;
          }
        }
        map.erase(arr[item]);
      }
      return -1;
    }
};