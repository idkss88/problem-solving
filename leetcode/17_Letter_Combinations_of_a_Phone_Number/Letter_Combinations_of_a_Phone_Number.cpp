#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    
    
    string convertToString(int digit) {
        switch (digit) {
            case 2:
                return "abc";
            case 3:
                return "def";
            case 4:
                return "ghi";
            case 5:
                return "jkl";
            case 6:
                return "mno";
            case 7:
                return "pqrs";
            case 8:
                return "tuv";
            case 9:
                return "wxyz";
                
            default:
                return "";
                
        }
        
        return "";
    } 
    
    vector<string> appendString(string str,int index) {
        
        vector<string> ans;
        if (index >= str.size()) return ans;
        
        char c = str[index];
        printf("test");
        string letter = convertToString(c-'0');
        vector<string> result = appendString(str,++index);
        
        if (!result.empty()) {        
        for (int i = 0 ; i < letter.size(); i++) {
            for (int j = 0 ; j <result.size(); j++ ) {
                ans.push_back(letter[i]+result[j]);
            }
        }
        } else {
            std::string s;
            for (int i = 0 ; i < letter.size(); i++) {
                ans.push_back(s+letter[i]);
            }
        }
         
         
        return ans;
       
        }
    
    vector<string> letterCombinations(string digits) {
        
        return appendString(digits,0);
    
    }
};