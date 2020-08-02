class Solution {
public:
    bool dfs(vector<int>& pos, int l, int r) {
        if(l >= r) return true;
        int root = pos[r];
        int k = l;
        while(k < r && pos[k] < root) k++;
        for(int i = k; i < r; i++)
            if(pos[i] < root) return false;
        return dfs(pos, l, k-1) && dfs(pos, k, r-1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        if(!postorder.size()) return true;
        return dfs(postorder, 0, postorder.size()-1);
    }
};