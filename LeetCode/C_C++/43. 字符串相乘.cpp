class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> A, B;
        for(int i = num1.size()-1; i >= 0; i--) A.push_back(num1[i]-'0');
        for(int i = num2.size()-1; i >= 0; i--) B.push_back(num2[i]-'0');
        vector<int> C(A.size() + B.size());

        for(int i = 0; i < A.size(); i++)
            for(int j = 0; j < B.size(); j++)
                C[i+j] += A[i] * B[j];
        for(int i = 0, t = 0; i < C.size() || t; i++)
        {
            t += C[i];
            if(i >= C.size()) C.push_back(t % 10);
            else C[i] = t % 10;
            t /= 10;
        }
        while(C.size() > 1 && !C.back()) C.pop_back();
        string str;
        for(int i = 0; i < C.size(); i++) str = to_string(C[i]) + str;
        return str;
    }
};