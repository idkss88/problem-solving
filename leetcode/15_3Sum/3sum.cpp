#include<string>
#include<vector>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        for (int i = 0 ; i < nums.size()-2; i++) {
            
            vector<int> result;
            
            for (int j = i+1 ; j < nums.size()-1; j++ ) {
                    
                for (int k = j+1; k < nums.size(); k++) {
                    
                    if (0 == (nums[i] + nums[j] + nums[k])) {
                        cout <<nums[i]<<":"<<nums[j]<<":"<< nums[k]<<endl;
                        result.push_back(nums[i]);
                        result.push_back(nums[j]);
                        result.push_back(nums[k]);
                        
                        ans.push_back(result);
                        result.clear();
                    } 
                } 
            }
        }
        
        return ans;
    }
};