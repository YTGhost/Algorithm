class Solution {
public:
    vector<int> a;
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        a.push_back(0);
        for(int i = 0; i < n; i++)
        {
            vector<int>::iterator it1 = find(a.begin(), a.end(), leftChild[i]);
            if(leftChild[i] != -1 && a.end() == it1)
            {
                a.push_back(leftChild[i]);
            }else if(leftChild[i] != -1 && a.end() != it1)
            {
                return false;
            }
            vector<int>::iterator it2 = find(a.begin(), a.end(), rightChild[i]);
            if(rightChild[i] != -1 && a.end() == it2)
            {
                a.push_back(rightChild[i]);
            }else if(rightChild[i] != -1 && a.end() != it2)
            {
                return false;
            }
        }
        for(int i = 0; i < n; i++)
        {
            vector<int>::iterator it3 = find(a.begin(), a.end(), i);
            if(it3 == a.end())
            {
                return false;
            }
        }
        return true;
    }
};