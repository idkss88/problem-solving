
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
     vector<string> ans;
     void recursive(int n, string& arry,int index,char bracket,int open, int close) {


           // cout << "do " << bracket <<endl;
            if (bracket == '(') {
                open++;
            } else {
                close++;
            }

            if ((open - close) < 0) {
                return;
            }

            if (bracket == '(') {
                if (open > n) return;
            } else {
                if (close > n) return;
            }

            if (index >= (n*2)) {
                return;
            }
            
            arry[index++] = bracket;

            
            if (open >= n && close >= n) {
                ans.push_back(arry);
                return;
            } 
            //next
            recursive(n,arry,index,'(',open,close);
            recursive(n,arry,index,')',open,close);

    }
    vector<string> generateParenthesis(int n) {
        string s;
        s.assign(2*n,' ');
        recursive(n,s,0,'(',0,0);
        return ans;
    }
};
int main() {
    Solution s;
    string str = "()()()()";
    s.generateParenthesis(5);

    for (auto& ret : s.ans) {
            for (auto& test : ret) {
                cout << test ;
            }
            cout << endl;
    }

    return 0;
};