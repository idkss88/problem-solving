#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        //우선 소트
        sort(nums.begin(),nums.end());
        int first = 0;
        int front,back;
        int closet = INT_MAX;
        int ans = 0;
        int sum = 0;
      
        for (int i = 0 ; i < nums.size()-1;i++) {
            
            first = nums[i];
    
            int front = i+1;
            int back = nums.size() -1;
            
            while( front < back ) {
                 vector<int> triplet = {first,nums[front], nums[back]};
                 sum = triplet[0] + triplet[1] + triplet[2];
                 int next_closet = abs(target - sum);
                // cout << "["<< i <<"]"<<next_closet << "sum: "<<sum<< endl;                      
                 if ( closet == INT_MAX ) {
                    closet = next_closet;
                    ans = sum;
                 } else {
                     if (next_closet < closet) {
                            closet =  next_closet;
                            ans = sum;
                     }
                 }
                    
                 if (sum < target) {
                     front++;
                     while(front < back && triplet[1] == nums[front]) front++;

                 } else if (sum > target) {
                     back--;
                     while(front < back && triplet[2] == nums[back]) back--;
                 } else {
                     // perfetc closet.
                     return target;
                 }                                      
            }
            
            while(i + 1 < nums.size() && nums[i] == nums[i+1]) i++;
            
        }
        
        return ans;
        
    }
};

int main(void) {
    Solution s;
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    s.threeSumClosest(nums,target);

    return 0;
}