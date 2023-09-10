class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> deg(numCourses);
        vector<vector<int>> edge(numCourses);
        int visited = 0;
        for(auto p : prerequisites) {
            deg[p[0]]++;
            edge[p[1]].push_back(p[0]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(deg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            res.push_back(t);
            visited++;
            for(int i = 0; i < edge[t].size(); i++) {
                deg[edge[t][i]]--;
                if(deg[edge[t][i]] == 0) {
                    q.push(edge[t][i]);
                }
            }
        }

        return visited == numCourses ? res : vector<int>{};
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        int d[numCourses];
        int tt = -1, hh = 0;
        int q[numCourses];
        memset(d, 0, sizeof d);
        memset(q, 0, sizeof q);
        // 初始化入度
        for(auto item : prerequisites) d[item[0]]++;
        for(int i = 0; i < numCourses; i++)
        {
            if(!d[i]){
                q[++tt] = i;
            }
        }
        while(hh <= tt)
        {
            int t = q[hh++];
            for(int i = 0; i < prerequisites.size(); i++)
            {
                if(prerequisites[i][1] == t){
                    d[prerequisites[i][0]]--;
                    if(d[prerequisites[i][0]] == 0) q[++tt] = prerequisites[i][0];
                } 
            }
        }
        if(tt == numCourses-1){
            for(int i = 0; i < numCourses; i++) ans.push_back(q[i]);
        }
        return ans;
    }
};