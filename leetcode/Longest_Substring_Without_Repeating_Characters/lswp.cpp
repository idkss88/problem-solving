#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iterator>
using namespace std;

class Solution {
public:
    //
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        unordered_map<char,int> map;
        int length =0;
        string::iterator itr;
        int curPosition = 0;

        for (itr = s.begin() ; itr != s.end(); itr++) {

            // 맵에 있으면 길이를 구한다?
            // ex) "abba" , "abcabcbb"
            if (map.find(*itr) != map.end() ) {
                if (curPosition <=  map[*itr]) {
                    cout << endl;
                    cout <<*itr; 
                    cout << ":"<<map[*itr]<< "->"; 
                    curPosition = map[*itr]+1;
                    length =  distance(s.begin(),itr) - map[*itr];
                    map[*itr] = distance(s.begin(),itr);
                    cout <<map[*itr]; 
                    if (length > max ) {
                        max = length;
                    }
                    continue;
                 }
                map[*itr] = distance(s.begin(),itr);
                cout <<map[*itr]; 
            }
                
            map.insert({*itr,distance(s.begin(),itr)});
            length++;
            if (length > max ) {
                max = length;
            }
            cout << *itr;  
        
        }
        //brute force
        /*
        for (itr = s.begin() ; itr != s.end(); itr++) {
            if (map.find(*itr) != map.end()) {
                    itr = s.begin() + map[*itr] + 1;
                    length = 0;
                    map.clear();
                }
                
                map.insert({*itr,distance(s.begin(),itr)});
                length++;
                if (length > max ) {
                    max = length;
                }
        }*/
        return max;    
    }
};

int main(void) {

    string str = "aabaab!bb";

    Solution s;
    cout << s.lengthOfLongestSubstring(str) << endl;
}