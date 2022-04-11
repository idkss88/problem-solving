#include <iostream>

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int diff = high-low;
        int ans = diff/2;
        ans+=low%2==1||high%2==1?1:0;
        return ans;
    }
};


int main(void) {
    Solution s;
    cout << s.countOdds(5,10) << endl;
    return 0;
}