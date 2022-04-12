#include<vector>
#include<iostream>
using namespace std;


//brute force
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        vector<int>::iterator s_itr1= nums1.begin();
        vector<int>::iterator s_itr2= nums2.begin();
        vector<int>::iterator e_itr1= nums1.end();
        vector<int>::iterator e_itr2= nums2.end();
        
        while(s_itr1 != e_itr1 || s_itr2 != e_itr2 ) {

            if (s_itr1 == e_itr1) {
                result.push_back(*s_itr2);
                s_itr2++;
            } else if ( s_itr2 == e_itr2) {
                result.push_back(*s_itr1);
                s_itr1++;
            } else if (*s_itr1 < *s_itr2) {
                result.push_back(*s_itr1);
                s_itr1++;
            } else {
                result.push_back(*s_itr2);
                 s_itr2++;
            }
        }

        //calc
        int medianIndex = 0;
        medianIndex = result.size()/2;
        if (result.size() % 2 == 0) {
            return double((result[medianIndex-1] + result[medianIndex]))/2;
        } else {
            return double(result[medianIndex]);
        }
    }
};

int main(void) {

    Solution s;

    vector<int> a;
    vector<int> b;

    a.push_back(1);
    a.push_back(2);

    b.push_back(3);
    b.push_back(4);
    cout << s.findMedianSortedArrays(a,b) << endl;
}
