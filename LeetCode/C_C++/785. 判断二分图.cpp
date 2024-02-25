// 染色法
class Solution {
public:
    int h[105];
    int e[20005];
    int ne[20005];
    int idx;
    int color[105];

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    bool dfs(int u, int c)
    {
        color[u] = c;
        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!color[j]){
                if(!dfs(j, 3-c)) return false;
            }else{
                if(color[j] == c) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        memset(h, -1, sizeof(h));
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < graph[i].size(); j++)
            {
                add(i, graph[i][j]), add(graph[i][j], i);
            }
        }

        bool sign = true;
        for(int i = 0; i < size; i++)
        {
            if(!color[i]){
                if(!dfs(i, 1)){
                    sign = false;
                    break;
                }
            }
        }
        return sign;
    }
};