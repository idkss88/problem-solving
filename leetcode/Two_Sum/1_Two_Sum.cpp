#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Brute Force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start = 0;
        int end = 0;
        vector<int> result;
        for (int i = 0; i < nums.size()-1 ; i++) {

            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);

                    return result;
                } 
            }
        }
        return result;
    }
};

int main() 
{   
    vector<int> a{2,7,11,15};
    vector<int> result;
    int target = 9;
    Solution s;
    result = s.twoSum(a,9);

    for (auto& element : result) {
        cout << element <<endl;
    }

    return 0;
}