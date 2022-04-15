#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<vector<char>> _map(1000,vector<char>(1000,0));
 
        //section 1

        bool nextSection = false;
        int depth = 0;
        int start = 0;
        for (auto& element : s) {

            if (nextSection == false) {
                //cout<< "push down" <<depth <<","<<start<<element << " ";
                _map[depth++][start] = element;

                if (depth == numRows) {
                    depth--;
                    nextSection = true;
                }
            } else {
                _map[--depth][++start] = element;
                //cout<< "push2 up" <<depth <<","<<start<<element << " ";

                if (depth == 0) {
                    depth++;
                    nextSection = false;
                }
            }
        }

        int i = 0; 
        string result = "";
        while(i < numRows) {
            for (auto& elemnt : _map[i]) {
                result += elemnt;
            }
            i++;
        }
        
        return result;
    }
};

int main(void) {
    Solution s;
    cout << s.convert("PAYPALISHIRING",4) << endl;
    return 0;
}