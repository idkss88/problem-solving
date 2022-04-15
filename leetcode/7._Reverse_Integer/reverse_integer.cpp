#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {

        bool flag = false;
        if (x == 0) return 0;
        if (x < 0) {
            flag = true;
        }
        string str = to_string(abs(x));
        int size = str.size();
        for (int i = 0 ; i < 10 - size ; i++) {
            str.append("0");

        }
        string r_str = string(str.rbegin(),str.rend());

        
        //-231 <= x <= 231 - 1
        if (((flag != true) && (r_str > to_string((1LL<<31)-1))) ||
         ((flag == true) && (r_str > to_string(1LL<<31)))) {
            return 0;
        } 

        return stoi(r_str) *  ((flag) ? -1 : 1);
    };
};

/*
int reverse(int x) {
       int rev = 0;
       while (x){
           int digit = x % 10;
           x /= 10;
           if ((rev > 0 && rev > (INT_MAX - digit)/10) | (rev < 0 && rev < (INT_MIN - digit)/10)) return 0;
           rev = rev * 10 + digit;
       }
       return rev;
   }
*/
int main (void) {

    Solution s;
    cout << to_string(1LL<<31)  << endl;
    cout << s.reverse(1534236469) << endl;
    return 0;
}