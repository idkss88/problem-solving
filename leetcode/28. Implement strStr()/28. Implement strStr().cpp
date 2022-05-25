#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int i=0;
        int j=0;
        int comp = j+i;
        if (needle.empty()) {
            return 0;
        }
        
        while( i < needle.size() && j < haystack.size()) {
            
            if (needle[i] == haystack[comp]) {
                i++;
                comp = j+i;
            } else {
                j++;
                i = 0;
                comp = j+i;
                
            }
        }
        //cout << "i:"<<i <<","<<"j:"<< j << endl;
        if ( i == needle.size()) {
            return j; 
        } else {
            return -1;
        }
    }
};

int main(void) {
    Solution s;

    string haystack = "hello";
    string needle = "ll";
    cout << s.strStr(haystack,needle) <<endl;;

}