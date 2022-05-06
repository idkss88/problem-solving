#include<algorithm>
#include<iostream>
#include<stack>

using namespace std;

class Solution {
private:
    char closedbracket(char& input) {
        switch (input) {
            case ')' :
                return '(';
            case '}' :
                return '{';
            case ']' :
                return '['; 
            default:
                return 'x';
        }
    }
public:
    bool isValid(string s) {
        
        stack<char> bucket;
        for (auto& c : s) {
            
            if(bucket.empty()) {
                bucket.push(c);
            } else {
                //check 
                char compare = bucket.top();              
                if (closedbracket(c) == compare) {
                    bucket.pop();
                } else {
                    bucket.push(c);
                }
            }
        }
        
        if (bucket.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main(void) {
    Solution s; 
    string str = "()[]{}";
    cout << s.isValid(str) << endl;
    return 0;
}
