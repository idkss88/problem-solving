#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        string r_s(s.rbegin(),s.rend());
        int sIndex = 0;
        int eIndex = 0;
        int last_sIndex = 0;
        int last_eIndex = 0;

        int count = 0;
        int prev = -1;
        int max = 0;
        int size = s.size();
         if (size == 1) return s;
        for (int i = 0 ; i < r_s.size(); i++) {
            int index = 0;
            int j = size-1-i;
            int prev = -1;
            cout<< ">> index " << index <<" j is " <<j<< endl;
            while( j < r_s.size()) {
                int value = s[index] - r_s[j];
                if (value == 0) {

                    if (prev == -1 || prev != 0) {
                        count = 0;
                        eIndex = sIndex;
                            cout<< "prev is " << prev <<" start is " <<index<< endl;

                        sIndex = index;
                        count++;
                        if (count > max ) {
                            max = count;
                        }
                    } 
                    else if (prev == 0) {
                        cout<< "prev is 0  eIndex is "<<eIndex<< endl;
                        eIndex = index;
                        count++;
                        if (count > max ) {
                            cout<< "change max to  "<<count<< endl;

                            max = count;
                            last_sIndex = sIndex;
                            last_eIndex = eIndex;

                        }
                    } else {
                        cout<< "check "<< endl;
                    }
                } 
                prev = value;
                index++;
                j++;
            }
        }
        for (int i = r_s.size() -1 ; i >= 0; i--) {
            int index = i;
            int j = size-(i+1);
            int prev = -1;
            cout<< ">> index " << index <<" j is " <<j<< endl;
            while( j < r_s.size()) {
                int value = s[index] - r_s[j];
                if (value == 0) {

                    if (prev == -1 || prev != 0) {
                        count = 0;
                        eIndex = sIndex;
                            cout<< "prev is " << prev <<" start is " <<index<< endl;

                        sIndex = index;
                        count++;
                        if (count > max ) {
                            max = count;
                        }
                    } 
                    else if (prev == 0) {
                        cout<< "prev is 0  eIndex is "<<eIndex<< endl;
                        eIndex = index;
                        count++;
                        if (count > max ) {
                            cout<< "change max to  "<<count<< endl;

                            max = count;
                            last_sIndex = sIndex;
                            last_eIndex = eIndex;

                        }
                    } else {
                        cout<< "check "<< endl;
                    }
                } 
                prev = value;
                index++;
                j++;
            }
        }

                 cout<< "s["<<last_sIndex<<"] : "<<", e["<<last_eIndex<<"] : "<< endl;

         cout<< "s["<<last_sIndex<<"] : "<<s[last_sIndex]<<", e["<<last_eIndex<<"] : "<< s[last_eIndex]<< endl;
        return s.substr(last_sIndex,last_eIndex-last_sIndex+1);
    }
};


int main(void) {
    Solution s;
    cout << s.longestPalindrome("abb") << endl;

}