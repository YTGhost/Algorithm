class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int visit = 0;
        vector<int> degs(numCourses);
        vector<vector<int>> edges(numCourses);
        for(auto prerequisite : prerequisites) {
            degs[prerequisite[0]]++;
            edges[prerequisite[1]].push_back(prerequisite[0]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(degs[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            auto course = q.front();
            q.pop();
            visit++;
            for(int i = 0; i < edges[course].size(); i++) {
                degs[edges[course][i]]--;
                if(degs[edges[course][i]] == 0) {
                    q.push(edges[course][i]);
                }
            }
        }

        return visit == numCourses;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            visited++;
            for(int i = 0; i < edge[t].size(); i++) {
                deg[edge[t][i]]--;
                if(deg[edge[t][i]] == 0) {
                    q.push(edge[t][i]);
                }
            }
        }

        return visited == numCourses;
    }
};

class Solution {
public:
    const static int N = 100010;
    int h[N], e[N], ne[N], idx;
    int q[N], d[N];
    int n;

    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    bool topsort() {
        int hh = 0, tt = -1;

        for(int i = 0; i < n; i++)
            if(!d[i]) q[++tt] = i;

        while(hh <= tt)
        {
            int t = q[hh++];
            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                d[j]--;
                if(!d[j]) q[++tt] = j;
            }
        }
        return tt == n-1;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        memset(h, -1, sizeof(h));
        for(auto x : prerequisites)
        {
            add(x[1], x[0]);
            d[x[0]]++;
        }
        return topsort();
    }
};