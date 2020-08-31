class Solution {
public:
    vector<int> st;
    int num;

    void dfs(vector<vector<int>>& rooms, int x) {
        st[x] = 1;
        num++;
        for(int i = 0; i < rooms[x].size(); i++)
        {
            if(!st[rooms[x][i]]) dfs(rooms, rooms[x][i]);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        st.resize(n);
        dfs(rooms, 0);
        return num == n;
    }
};