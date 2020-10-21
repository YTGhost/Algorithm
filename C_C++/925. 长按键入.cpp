class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int p1 = 0;
        int p2 = 0;
        int s1 = name.size();
        int s2 = typed.size();
        while(p2 < s2)
        {
            if(p1 < s1 && name[p1] == typed[p2]) {
                p1++;
                p2++;
            } else if(name[p1-1] == typed[p2]) {
                p2++;
            } else {
                return false;
            }
        }
        return p1 == s1;
    }
};